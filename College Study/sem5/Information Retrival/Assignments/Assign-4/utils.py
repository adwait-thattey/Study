import sys
import nltk
from nltk.tokenize import RegexpTokenizer
import os, binascii
from operator import itemgetter

def hashshingle(token, hashmap, DT):

  for i in range(len(token)-2):
          tri_shingle = token[i]+token[i+1]+token[i+2]
          if tri_shingle not in hashmap:
              hashmap[tri_shingle] = binascii.crc32(bytes(tri_shingle, 'utf-8'))  & 0xffffffff  
          DT.add(hashmap[tri_shingle])



def tokenizer(corpus):
        
    tokenize = RegexpTokenizer(r'\w+')
    token = tokenize.tokenize(corpus.lower())

    return token




def jaccard_similarity(DT):

  jacc_sim= {}
  ind = 1
  for doc1 in DT:
    scores = []
    for doc2 in DT:
      jacc_sim_score = (len(DT[doc1] & DT[doc2])/len(DT[doc1] | DT[doc2]))*100
      scores.append((doc2, jacc_sim_score))
    sorted_scores = sorted(scores, key=itemgetter(1), reverse=True)
    jacc_sim[doc1] = sorted_scores
    if ind %50 == 0:
      print(ind, 'done')
    ind+= 1
  return jacc_sim