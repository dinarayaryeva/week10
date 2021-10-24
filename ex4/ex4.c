#include <dirent.h> 
#include <stdio.h> 
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){

  struct stat sb; //current file status
  DIR *d; //working directory pointer
  struct dirent *dir; //current file pointer
  d = opendir("tmp");

  if (d) { //if directory is open then

    while ((dir = readdir(d)) != NULL) {//while not end of directory

      if (dir->d_type==DT_REG){ //if inner file is the regular file

      char path[100]; //path buffer
      *path = '\0'; 
      strcat(path,"tmp/");
      strcat(path,dir->d_name);
      stat(path, &sb);
      
      if (sb.st_nlink>=2) { //if file has >=2 links then

        printf("%s - ", dir->d_name);
        struct stat sb2;
        DIR *d2; //new pointer for accessing the same directory
        struct dirent *dir2; //new pointer for inner file
        d2 = opendir("tmp"); 
        if (d2) { //if directory is accessible then

        while ((dir2 = readdir(d2)) != NULL) { //go through all files of the same directory again

            char path2[] = "tmp/";
            strcat(path2,dir2->d_name);
            stat(path2, &sb2);

        if (sb2.st_ino==sb.st_ino) { //if files have the same i-node then

            printf("%s ", dir2->d_name);
        }
        }
        }
        closedir(d2);
        }
        printf("\n");
    }
  }
  }
  closedir(d);
  return(0);
}