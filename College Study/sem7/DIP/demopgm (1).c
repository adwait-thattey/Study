#include <stdio.h>
#include <stdlib.h>
#define MAX_ROWS 2000
#define MAX_COLS 2000
#define MAX_LENGTH 256
#define MAX_VALUE 255

int pgm_Read(char *fileName, long *rows, long *cols,
             unsigned char image[][MAX_COLS]);

int pgm_Write(char *filename, long rows, long cols,
              unsigned char image[][MAX_COLS], char *comment_string);

void compliment(long rows, long cols, unsigned char image[MAX_ROWS][MAX_COLS]);

long int overallGreyValue = 0;

void main()
{
  long rows, cols;                         /* dimensions of the pixmap */
  unsigned char image[MAX_ROWS][MAX_COLS]; /* 2D array to hold the image */
  char userInput[60];                      /* input from user */
  int readOK, loopCondition, request;      /* two flags and user's request */
  int writeOK;                             /* flag for succesful write */
  loopCondition = 1;                       /* set loop condition to "true" */

  printf("input filename:\n"); /*  and manipulate it. */
  scanf("%s", userInput);
  readOK = pgm_Read(userInput, &rows, &cols, image);

  if (readOK)
  {
    FILE *fp = fopen(userInput, "r");
    fseek(fp, 0L, SEEK_END);

    // calculating the size of the file
    long int f_size = ftell(fp);
    fclose(fp);
    fp = fopen(userInput, "r");
    char line[MAX_LENGTH];
    fgets(line, MAX_LENGTH, fp);
    while (line[0] == '#' || line[0] == '\n')
      fgets(line, MAX_LENGTH, fp);
    if (line[0] == 'P' && (line[1] == '1'))
    {
      printf("File format is PBM\n");
    }
    else if (line[0] == 'P' && (line[1] == '2'))
    {
      printf("File format is PGM\n");
    }
    else if (line[0] == 'P' && (line[1] == '3'))
    {
      printf("File format is PPM\n");
    }
    printf("Size of the file is %ld bytes \n", f_size);
    printf("file height is %ld\n", rows);
    printf("file width is %ld\n", cols);
    // char ch = fgetc(fp);
    // printf("%c\n", ch);
    compliment(rows, cols, image);
    printf("Overall Greyvalue is %ld\n", overallGreyValue);
  }

  /* if file was read in properly (or synthesized) display the image */
  if (readOK)
  {
    writeOK = pgm_Write("demo.pgm", rows, cols, image, "test");
    if (writeOK)
    {
      system(""); /* system call */
    }
  }
}

void compliment(long rows, long cols, unsigned char image[MAX_ROWS][MAX_COLS])
{
  long i, j;
  for (i = 0; i < rows; i++)
  {
    for (j = 0; j < cols; j++)
    {
      image[i][j] = MAX_VALUE - image[i][j];
      overallGreyValue += image[i][j];
    }
  }
  overallGreyValue = overallGreyValue / (rows * cols);
}

int pgm_Read(char *fileName, long *rows, long *cols,
             unsigned char image[MAX_ROWS][MAX_COLS])
{
  FILE *file_Pointer;    /* for file buffer */
  char line[MAX_LENGTH]; /* for character input from file */
  int maximumValue = 0;  /* max value from header */
  int binary;            /* flag to indicate if file is binary (P5)*/
  long number_read = 0;  /* counter for number of pixels read */
  long i, j;             /* (i,j) for loops */
  int test, temp;        /* for detecting EOF(test) and temp storage */

  /* Open the file, return an error if necessary. */
  if ((file_Pointer = fopen(fileName, "r")) == NULL)
  {
    printf("ERROR: cannot open file\n\n");
    fclose(file_Pointer);
    return (0);
  }

  // fseek(tempF, 0L, SEEK_END);

  // // calculating the size of the file
  // *f_size = ftell(tempF);
  /* Initialize columnsidth, and height */
  *cols = *rows = 0;

  /* Check the file signature ("Magic Numbers" P2 and P5); skip comments
       * and blank lines (CR with no spaces before it).*/
  fgets(line, MAX_LENGTH, file_Pointer);
  while (line[0] == '#' || line[0] == '\n')
    fgets(line, MAX_LENGTH, file_Pointer);
  if (line[0] == 'P' && (line[1] == '2'))
  {
    binary = 0;
    /*   printf ("\nFile Format: P2\n"); */
  }
  else if (line[0] == 'P' && (line[1] == '5'))
  {
    binary = 1;
    /*  printf ("\nFORMAT: P5\n"); */
  }
  else
  {
    printf("ERROR: incorrect file format, This is not a .pgm file type, kindly enter a .pgm file\n");
    fclose(file_Pointer);
    return (0);
  }

  /* Input the width, height and maximum value, skip comments and blank
       * lines. */
  fgets(line, MAX_LENGTH, file_Pointer);
  while (line[0] == '#' || line[0] == '\n')
    fgets(line, MAX_LENGTH, file_Pointer);
  sscanf(line, "%ld %ld", cols, rows);

  fgets(line, MAX_LENGTH, file_Pointer);
  while (line[0] == '#' || line[0] == '\n')
    fgets(line, MAX_LENGTH, file_Pointer);
  sscanf(line, "%d", &maximumValue);

  /* display specifications and return an error if h,w, or
      *  maximum value is illegal.*/
  /*    printf("Rows: %ld   Columns: %ld\n",*rows,*cols); */
  /*       printf("Maximum value: %d\n\n",maximumValue); */

  if ((*cols) < 1 || (*rows) < 1 || maximumValue < 0 || maximumValue > MAX_VALUE)
  {
    printf("ERROR: invalid file specifications (cols/rows/max value)\n\n");
    fclose(file_Pointer);
    return (0);
  }
  else if ((*cols) > MAX_COLS || (*rows) > MAX_ROWS)
  {
    printf("ERROR: increase MAX_ROWS/MAX_COLS in PGM.h");
    fclose(file_Pointer);
    return (0);
  }
  /* Read in the data for binary (P5) or ascii (P2) PGM formats   */
  if (binary)
  {
    for (i = 0; i < (*rows); i++)
    {
      number_read += fread((void *)&(image[i][0]),
                           sizeof(unsigned char), (*cols), file_Pointer);
      if (feof(file_Pointer))
        break;
    }
  }
  else
  {
    for (i = 0; i < (*rows); i++)
    {
      for (j = 0; j < (*cols); j++)
      {
        test = fscanf(file_Pointer, "%d", &temp);
        if (test == EOF)
          break;
        image[i][j] = (unsigned char)temp;

        number_read++;
      }
      if (test == EOF)
        break;
    }
  }

  /*    printf ("  Rows * Columns = %ld\n",(*rows)*(*cols)); */
  /*       printf ("  Number of pixels read = %ld\n\n",number_read); */

  /* Insure the number of pixels read is at least the
       *   number indicated by w*h.
       * If not, return an error message, but proceed */
  if (number_read < ((*rows) * (*cols)))
  {
    printf("ERROR: fewer pixels than rows*cols indicates\n\n");
  }

  /* close the file and return 1 indicating success */
  fclose(file_Pointer);
  return (1);
}

/* INPUT: a filename (char*), the dimensions of the pixmap (rows,cols of
 *   type long), and a pointer to a 2D array (MAX_ROWS x MAX_COLS) in row
 *   major order.
 * OUTPUT: an integer is returned indicating if the desired file was written
 *   (in P5 PGM format (binary)).  A 1 is returned if the write was completed
 *   and 0 if it was not.  An error message is returned if the file is not
 *   properly opened.  
 */
int pgm_Write(char *filename, long rows, long cols,
              unsigned char image[MAX_ROWS][MAX_COLS], char *comment_string)
{
  FILE *file;        /* pointer to the file buffer */
  int maxval;        /* maximum value in the image array */
  long nwritten = 0; /* counter for the number of pixels written */
  long i, j;         /* for loop counters */

  /* return 0 if the dimensions are larger than the image array. */
  if (rows > MAX_ROWS || cols > MAX_COLS)
  {
    printf("ERROR: row/col specifications larger than image array:\n");
    return (0);
  }

  /* open the file; write header and comments specified by the user. */
  if ((file = fopen(filename, "w")) == NULL)
  {
    printf("ERROR: file open failed\n");
    return (0);
  }
  fprintf(file, "P5\n");

  if (comment_string != NULL)
    fprintf(file, "# %s \n", comment_string);

  /* write the dimensions of the image */
  fprintf(file, "%ld %ld \n", cols, rows);

  /* NOTE: MAXIMUM VALUE IS WHITE; COLOURS ARE SCALED FROM 0 - */
  /* MAX_VALUE IN A .PGM FILE. */

  /* WRITE MAXIMUM VALUE TO FILE */
  fprintf(file, "%d\n", (int)255);

  /* Write data */

  for (i = 0; i < rows; i++)
  {
    nwritten += fwrite((void *)&(image[i][0]), sizeof(unsigned char),
                       cols, file);
  }

  /*     printf ("\nNumber of pixels total(from rows*cols): %ld\n",rows*cols); */
  /*       printf ("Number of pixels written: %ld\n\n",nwritten); */

  fclose(file);
  return (1);
}
