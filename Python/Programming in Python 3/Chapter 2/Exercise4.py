import sys
from xml.sax.saxutils import escape

maxwidth = 0
def process_options():
    if len(sys.argv) > 1 and sys.argv[1] in ("-h", "--help"):
        explanation = \
        """usage:\n {0} [maxwidth=int] [format=str] < infile.csv > outfile.html
        
        maxwidth is an optional integer; if specified, it sets the maximum
        number of characters that can be output for string fields,
        otherwise a default of 100 characters is used.
        
        format is the format to use for numbers; if not specified it
        defaluts to ".0f". """.format(sys.argv[0])
        print (explanation)
        return (None, None)
    
    maxwidth = 100
    fmt = ".0f"
    if len(sys.argv) == 2:
        if sys.argv[1].startswith("maxwidth="):
            try:
                maxwidth = int(sys.argv[1].split("=")[1])
            except ValueError as ve:
                pass
        elif sys.argv[1].startswith("format="):
            fmt = sys.argv[1].split("=")[1]
    elif len(sys.argv) > 2:
        for pattern in sys.argv[1:3]:
            if pattern.startswith("maxwidth="):
                try:
                    maxwidth = int(pattern.split("=")[1])
                except ValueError as ve:
                    pass
            elif pattern.startswith("format="):
                fmt = pattern.split("=")[1]
            
    return (maxwidth, fmt)

def main():
    (maxwidth, fmt) = process_options()
    if maxwidth is None:
        exit()
        
    print_start()
    count = 0
    while True:
        try:
            line = input()
            if count == 0:
                color = "lightgreen"
            elif count % 2:
                color = "white"
            else:
                color = "lightyellow"
            print_line(line, color, maxwidth, fmt)
            count += 1
        except EOFError:
            break
    print_end()


def print_start():
    print("<table border='1'>")


def print_line(line, color, maxwidth, fmt):
    print("<tr bgcolor='{0}'>".format(color))
    fields = extract_fields(line)
    for field in fields:
        if not field:
            print("<td></td>")
        else:
            number = field.replace(",", "")
            try:
                x = float(number)
                f = "<td align='right'>{{0:{0}}}</td>".format(fmt)
                print(f.format(round(x)))
            except ValueError:
                field = field.title()
                field = field.replace(" And ", " and ")
                if len(field) <= maxwidth:
                    field = escape(field)
                else:
                    field = "{0} ...".format(
                            escape(field[:maxwidth]))
                print("<td>{0}</td>".format(field))
    print("</tr>")


def extract_fields(line):
    fields = []
    field = ""
    quote = None
    for c in line:
        if c in "\"'":
            if quote is None: # start of quoted string
                quote = c
            elif quote == c:  # end of quoted string
                quote = None
            else:
                field += c    # other quote inside quoted string
            continue
        if quote is None and c == ",": # end of a field
            fields.append(field)
            field = ""
        else:
            field += c        # accumulating a field
    if field:
        fields.append(field)  # adding the last field
    return fields

def print_end():
    print("</table>")


main()
