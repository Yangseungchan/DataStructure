# Introduction to using GITHUB.

## (1) Initialization

1. Deleting previous account information

     \$ git config --global user.email --unset credential.helper

     $ git config --global user.name --unset credential.helper

2. Inputing email and name information for initialization
    
     $ git config --global user.email --"input@your.mail"

     $ git config --global user.name "Your name" or "nickname"

    * if there is an error like "error: cannot overwrite multiple values with a single value", then you can use these commands.

     $ git config --global --replace-all user.email "your@mail.com"

    * Erasing all previously enrolled email and replacing them with new mail which you input at this command.)

     $ git config --global --replace-all user.name "Yangseungchan"

    * Erasing all previously enrolled name and replacing them with new name which you input at this command.)

3.  Make your directory for using at your own repository. (Using cmd such as "mkdir", "cd")

    Let's assume that your directory name is "example" Then,

     $ mkdir example

     $ cd example
    
    * You can check your current directory by using cmd "pwd"

4. Start of git

     $ git init 
    
    * You can check .git folder in your directory by using cmd "ls -A"


## (2) Adding and Committing the files

1. Add the file

    Let's assume the added file is "example.c"

     $ git add example.c

2. Commit

     $ git commit -m "example has been added"

    * In the position of "example has been added", you can input any message to indicate the status of update.


* git status check cmd

     $ git show
     
     $ git log

     $ git shortlog

     $ git diff
     
     $ git status

3. Check the status whether there is any added contents.

     $ git diff

    * If it figures out that there is an any change, then you have to use cmd "add" and "commit" to reflect the changes.

## (3) Make your own repository in github homepage

     You need to copy the URL of your repository.

## (4) Linking the current directory with the github repository

1. Connection
  
    * Let's assume your repository link as "https://github.com/Yangseungchan/DataStructure.git"

     $ git remote origin master "https://github.com/Yangseungchan/DataStructure.git"

2. PUSH

     $ git push origin master

    Then you can check that the added items are reflected on the github repository.

    * If you have the error such as; error: failed to push some refs to "https://github.com/Yangseungchan/DataStructure.git", then
    you can solve this problem by inputting "git pull origin master"

    * If there is the problem when you input "git pull origin master" such as; "fatal: refusing to merge unrelated histories", then
    you can solve this problem by inputting "git pull origin master --allow-unrelated-histories". After that, what you have to do is to start the processes
    from commiting.
     
  





    

    





