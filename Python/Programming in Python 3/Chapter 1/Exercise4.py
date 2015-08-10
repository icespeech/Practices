from random import choice
import sys

articles = ['the', 'a', 'this', 'that', 'his', 'her', 'your', 'my', 'their', 'its']
subjects = ['cat', 'dog', 'fox', 'rabbit', 'pig', 'man', 'woman']
verbs    = ['laughed', 'jumped', 'hoped', 'walked', 'played']
adverbs  = ['loudly', 'badly', 'quietly', 'well']

times = 5
if len(sys.argv) > 1:
    try:
        tmp = int(sys.argv[1])
        if 1 <= tmp <= 10:
             times = tmp
    except ValueError:
        pass
    
for i in range(0, times):
    if choice([True, False]):
        print (' '.join([choice(articles), choice(subjects), choice(verbs), choice(adverbs)]))
    else:
        print (' '.join([choice(articles), choice(subjects), choice(verbs)]))