This file contains the explanation for the code.
The report.pdf is also included in the zip which contains the results 

The algo.c contains the code which performs the r-fold cross validation.

The files 'seeds_dataset.txt' and 'optdigits.tra' contain the original dataset.

DATASET 1
A c program 'randomize.c' first randomizes the data in 'seeds_dataset.txt' files and saves it again as 'rand_seeds_dataset.txt' in a proper format that is readable by the algo.c code. This is dome so that data can be easily divided in R folds and each fold contains near equal amounts of entities from each class.

'rand_seeds_dataset' is also included in the zip file

DATASET2
algo.c requires the input to be in the format in which each line contains f+1 space seperated values. First f values are of type double and represent features. The (f+1)th value is the class that element belongs to.

The format is different in optdigits.tra which uses comma as delimiter instead of space. 

A code converter.c converts this file into another file 'spaced_optdigits.txt' that uses space as a delimiter.

spaced_optdigits.txt is also included in the zip file
 

THE INPUT TO algo.c MUST BE EITHER 'rand_seeds_dataset.txt' OR 'spaced_optdigits.txt'

See the main function in the algo.c to know how to change between these 2 files.

The zip also contains 2 files result_dataset1.txt and result_dataset2.txt containing the accuracies for different values of k and p
 
