# The windows version
import sys
import unicodedata


def print_unicode_table(words):
    filename = "unicode-table.txt"
    with open(filename, "w", encoding="utf8") as file:
        file.write("decimal   hex   chr  {0:^40}\n".format("name"))
        file.write("-------  -----  ---  {0:-<40}\n".format(""))

        code = ord(" ")
        end = min(0xD800, sys.maxunicode) # Stop at surrogate pairs

        while code < end:
            c = chr(code)
            name = unicodedata.name(c, "*** unknown ***")
            if words is None or (set(words) <= set(name.lower().split())):
                file.write("{0:7}  {0:5X}  {0:^3c}  {1}\n".format(code, name.title()))
            code += 1
    print("wrote results to", filename)


words = None
if len(sys.argv) > 1:
    if sys.argv[1] in ("-h", "--help"):
        print("usage: {0} [string]".format(sys.argv[0]))
    else:
        words = [ param.lower() for param in sys.argv[1:] ]
        print_unicode_table(words)
