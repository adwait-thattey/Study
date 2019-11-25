the task is to de-duplicate similar articles. For this we find similar articles ie given an articles find the top 10 most similar articles. 
To solve this problem we use jaccard distance (intersection divided by union) between 2 articles.
Each article is represented as a set, where enteries in the set are the hashes of k=3 shingles. 

