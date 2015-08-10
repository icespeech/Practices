from random import choice
articles = ['the', 'a', 'this', 'that', 'his', 'her', 'your', 'my', 'their', 'its']
subjects = ['cat', 'dog', 'fox', 'rabbit', 'pig', 'man', 'woman']
verbs    = ['laughed', 'jumped', 'hoped', 'walked', 'played']
adverbs  = ['loudly', 'badly', 'quietly', 'well']

for i in range(0, 5):
    if choice([True, False]):
        print (' '.join([choice(articles), choice(subjects), choice(verbs), choice(adverbs)]))
    else:
        print (' '.join([choice(articles), choice(subjects), choice(verbs)]))