#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

//to calculate real human time
void realtime(time_t ot){
  char currenttime[24];
  strftime(currenttime, 24, "%b %d %H:%M", localtime(&ot));
  //instead of returning a string with the time, i just print the time in the
  //function itself
  printf("%s", currenttime);
}

int listdir(const char * path)
{
  struct dirent * entry;
  DIR * dp;

  dp = opendir(path);
  if(dp == NULL)
  {
    perror("could not open directory");
    return 1;
  }

  // initiate the variables outside the loop
  struct stat file;
  struct passwd * pwd;
  struct group * grp;


  while((entry = readdir(dp)) != NULL)
  {
    /* This loop iterates over each file entry in the directory.
     * Each file name is stored in entry->d_name. */

    //to hide any hidden file in UNIX which typically begin with .
    if(entry->d_name[0] != '.'){

      stat(entry->d_name, &file);

      //file type
      if(S_ISDIR(file.st_mode) == 1){
        printf("d");
      }
      else if(S_ISBLK(file.st_mode) == 1){
        printf("b");
      }
      else if(S_ISLNK(file.st_mode) == 1){
        printf("l");
      }
      else if(S_ISREG(file.st_mode) == 1){
        printf("-");
      }
      else if(S_ISCHR(file.st_mode) == 1){
        printf("c");
      }
      else if(S_ISFIFO(file.st_mode) == 1){
        printf("p");
      }
      else if(S_ISSOCK(file.st_mode) == 1){
        printf("s");
      }

      //permissions
      printf( (file.st_mode & S_IRUSR) ? "r" : "-");
      printf( (file.st_mode & S_IWUSR) ? "w" : "-");
      printf( (file.st_mode & S_IXUSR) ? "x" : "-");
      printf( (file.st_mode & S_IRGRP) ? "r" : "-");
      printf( (file.st_mode & S_IWGRP) ? "w" : "-");
      printf( (file.st_mode & S_IXGRP) ? "x" : "-");
      printf( (file.st_mode & S_IROTH) ? "r" : "-");
      printf( (file.st_mode & S_IWOTH) ? "w" : "-");
      printf( (file.st_mode & S_IXOTH) ? "x" : "-");

      printf("\t");

      //links
      printf("%d", file.st_nlink);

      printf("\t");

      //user and groups
      if((pwd = getpwuid(file.st_uid)) != NULL){
        printf("%s", pwd->pw_name);
      }

      printf("\t");

      if((grp = getgrgid(file.st_gid)) != NULL){
        printf("%s", grp->gr_name);
      }

      printf("\t");

      //size
      printf("%llu", (unsigned long long)file.st_size);

      printf("\t");

      //name
      realtime(file.st_mtime);

      printf("\t");

      puts(entry->d_name);
    }

  }

  closedir(dp);

  return 0;
}

int main(int argc, char * argv[])
{
  if(argc == 1)
    return listdir(".");
  else
    return listdir(argv[1]);
}
