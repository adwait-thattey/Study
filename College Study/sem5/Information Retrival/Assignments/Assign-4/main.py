from utils import *
import constants

DT = {}
hashmap = {}

articles_dir = constants.DATASET_DIR
list_corpus = os.listdir(articles_dir)
current_dir = os.path.dirname(os.path.abspath(__file__))

for index, article in enumerate(list_corpus):
    print('parsing ', index + 1)
    with open(os.path.join(current_dir, articles_dir, article), 'r') as f:
        corpus = f.read()
        words = tokenizer(corpus)
        articleID = words[0]
        del (words[0])
        DT[articleID] = set()
        hashshingle(words, hashmap, DT[articleID])

jacc_sim = jaccard_similarity(DT)
for k, v in jacc_sim.items():
    print('document ', k, '\ntop 10 similar dataset: ', end='')
    for dc in v[:10]:
        print('( ' + dc[0] + " {0:.2f}".format(dc[1]) + ')', end=' ')
    print()
print()
