#include <bits/stdc++.h>
#include <windows.h>
#include <dirent.h>
// #include <experimental/filesystem>

// namespace fs = std::experimental::filesystem;
using namespace std;
void createFile(string filename)
{
    fstream file;
    file.open(filename, ios::out);
    if (!file)
    {
        cout << "Error in creating file!!!";
    }
    else
        cout << "File created" << endl;
    file.close();
}

void deleteFile(char filename[])
{
    int status;
    status = remove(filename);
    if (status == 0)
        cout << "File is deleted" << endl;
    else
        cout << "File does not deleted" << endl;
}

void renameFile(char oldname[], char newname[])
{
    if (rename(oldname, newname) == 0)
    {
        cout << "File renamed successfully." << endl;
    }
    else
        perror("Error");
}

void copyFile(char source[], char destination[])
{
    if (CopyFile(source, destination, true))
    {
        cout << "File copied successfully." << endl;
    }
    else
        cout << "Error occured." << endl;
}

void moveFile(char source[], char destination[])
{
    if (CopyFile(source, destination, true))
    {
        int status = remove(source);
        cout << "File moved successfully." << endl;
    }
    else
        cout << "Error occured." << endl;
}

void dirFile()
{
    struct dirent *d;
    DIR *dr;
    dr=opendir(".");
    if ((d = readdir(dr)) != NULL)
    {
        cout<<"folders are "<<endl;
        while((d=readdir(dr))!=NULL){
            cout<<d->d_name<<endl;            
        }
        closedir(dr);
    }
    else
    {
        cout<<"no file"<<endl;
    }
}
int main(int argc, char **argv)
{
    if (argc == 1)
    {
        cout << "No command inputed." << endl;
    }
    else
    {
        string create = "create";
        string del = "delete";
        string mov = "move";
        string ren = "rename";
        string cp = "copy";
        string dr = "ls";
        if (argv[1]==create)
        {
            createFile(argv[2]);
        }
        else if (argv[1]==del)
        {
            deleteFile(argv[2]);
        }
        else if (argv[1]== mov)
        {
            moveFile(argv[2], argv[3]);
        }
        else if (argv[1]==ren)
        {
            renameFile(argv[2], argv[3]);
        }
        else if (argv[1]==cp)
        {
            copyFile(argv[2], argv[3]);
        }
        else if (argv[1]== dr)
        {
            dirFile();
        }
    }
}
//  F:/3Y2S/OS/LAB/task1/l2.txt      F:/3Y2S/OS/LAB/task1/copy/l2.txt
// F:\3Y2S\OS\LAB\task1\losser.txt
