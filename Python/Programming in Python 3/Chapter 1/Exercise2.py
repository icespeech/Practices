numbers = []

while True:
    try:
        input_str = input('enter a number or Enter to finish: ')
        if input_str == '':
            print ('numbers: ', numbers)
            print ('count = {0} sum = {1} lowest = {2} highest = {3} mean = {4}'.format(len(numbers), sum(numbers), min(numbers), max(numbers), sum(numbers)/len(numbers)))
            break
            
        else:
            numbers.append(int(input_str))

    except ValueError as ve:
        print (ve)