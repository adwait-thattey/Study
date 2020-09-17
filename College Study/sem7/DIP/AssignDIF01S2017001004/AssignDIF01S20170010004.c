#include <stdio.h>
#include <stdlib.h>
#define MAX_ROWS 2000
#define MAX_COLS 2000
#define MAX_LENGTH 256
#define MAX_VALUE 255

int read_image(char *, long *, long *,
             unsigned char[][MAX_COLS]);

int write_image(long , long ,
              unsigned char[][MAX_COLS], char *);

void compliment(long , long , unsigned char[MAX_ROWS][MAX_COLS]);

long int overallGreyValue = 0;

void main()
{
  long rows, cols;                         /* dimensions of the pixmap */
  unsigned char image[MAX_ROWS][MAX_COLS]; /* 2D array to hold the image */
  int read_flag, loopCondition, request;      /* two flags and user's request */
  int writeOK;                             /* flag for succesful write */
  loopCondition = 1;                       /* set loop condition to "true" */

  read_flag = read_image("lena512.pgm", &rows, &cols, image);

  if (read_flag)
  {
    FILE *fp = fopen("lena512.pgm", "r");
    fseek(fp, 0L, SEEK_END);

    long int f_size = ftell(fp);
    fclose(fp);


    printf("Size : %ld bytes \n", f_size);
    printf("Height :  %ld \n", rows);
    printf("Width : %ld\n", cols);
    compliment(rows, cols, image);
    printf("Overall Greyvalue : %ld\n", overallGreyValue);
  }

  if (read_flag)
  {
    int write_flag = write_image(rows, cols, image, "nvm");
    if (write_flag)
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

int read_image(char *fileName, long *rows, long *cols,
             unsigned char image[MAX_ROWS][MAX_COLS])
{
  FILE *file_Pointer;    
  char line[MAX_LENGTH]; 
    int maximumValue = 0;   
  int binary;            
  long number_read = 0;   
  long i, j;             
  int test, temp;        

    file_Pointer = fopen(fileName, "r");
  if (file_Pointer == NULL)
  {
    printf("ERROR: cannot open file\n\n");
    fclose(file_Pointer);
    return (0);
  }


  *cols = *rows = 0;


  fgets(line, MAX_LENGTH, file_Pointer);
  while (line[0] == '#' || line[0] == '\n')
    fgets(line, MAX_LENGTH, file_Pointer);


  fgets(line, MAX_LENGTH, file_Pointer);
  while (line[0] == '#' || line[0] == '\n')
    fgets(line, MAX_LENGTH, file_Pointer);
  sscanf(line, "%ld %ld", cols, rows);

  fgets(line, MAX_LENGTH, file_Pointer);
  while (line[0] == '#' || line[0] == '\n')
    fgets(line, MAX_LENGTH, file_Pointer);
  sscanf(line, "%d", &maximumValue);

 
    for (i = 0; i < (*rows); i++)
    {
      number_read += fread((void *)&(image[i][0]),
                           sizeof(unsigned char), (*cols), file_Pointer);
      if (feof(file_Pointer))
        break;
    }

}

int write_image(long rows, long cols,
              unsigned char image[MAX_ROWS][MAX_COLS], char *comment_string)
{
  FILE *out_file;        
  int maxval;        
  long nwritten = 0; 
  long i, j;         

  if (rows > MAX_ROWS || cols > MAX_COLS)
  {
    printf("ERROR: row/col specifications larger than image array:\n");
    return (0);
  }

  out_file = fopen("complement_lena.pgm", "w");
  if (out_file == NULL)
  {
    printf("ERROR: file open failed\n");
    return (0);
  }
  fprintf(out_file, "P5\n");


  fprintf(out_file, "%ld %ld \n", cols, rows);

  fprintf(out_file, "%d\n", (int)255);


  for (i = 0; i < rows; i++)
  {
    nwritten += fwrite((void *)&(image[i][0]), sizeof(unsigned char),
                       cols, out_file);
  }

  fclose(out_file);
  return (1);
}
