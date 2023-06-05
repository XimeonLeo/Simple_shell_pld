# Simple_shell_pld
Just working on the basic concept of simple shell

#THOUGHT PROCESS FOR MY SIMPLE SHELL... XL

'''

*😃✍️ I need to get inputs from the user... I'll use "getline()"

getline() always add a new line character, I need to find a way to remove that!!!

'''

* 🥵🥶After getting the input(command), I'll need to break(parse) the input gotten so as to work on them individually... I'll use "strtok()"

'''

strtok() breaks an array of strings into tokens using a specific delimeter 😜
Come on, go read some more😌

🤔🤔Remember, all this commands are executable files somewhere in my shell.

💡💡I need to know if the command gotten from the user is a valid one.

'''

*🙉🙉 I can use "stat()" to check it a file exits...😃 

😔 But for me to really know, I need to have the full path for that particular file🥹😭

'''
No wonder!!😀
If I type "ls" it works. If I also type in "/bin/ls" it also works. 🤔🤔

That means I need to find a way to merge the command and it's full path 🫨🫨

I need to get the path variable... It contains some paths where I can find these command... Well, that's if they are valid.
😌😌😌

I know that the path variable can be gotten from the environment variable which can be gotten by passing a third argument to my main function 😂😂😂
Funny right??
int main(int ac, char **av, char **ev)

😟But I'm not allowed to use the standard function getenv()... That would have been easier 🙆‍♂️🤦‍♂️

🥺🥺
I'll just have to find a way to loop through the environment variable and use the function "strcmp()" to locate my path variable 🤔😃

Oh no!!!... I'll have to write this function myself 😭😭
Wait!!! I've done them before😃😂
(0x05, 0x06, 0x07)... I can get all the str functions I wrote from there 🕺🕺🕺🕺

Now, all I need to do is concatenate the command passed with all the full path gotten from my path variable using "strcat()" and then pass it to my "stat()" function to see if it truly exits😌😎

If it wasn't found, I'll just print out an error message probably using "perror()"🤪😜

If it was found...🥹🥹 I'll need to execute it 🤭
I'm going to use "execve()" for that😈😈

But execve() overwrites the current process🥹
Once it's done executing, it will overwrites the rest of the program 🙆‍♂️🙆‍♂️🙆‍♂️ what do I do!!!😔

Why now create another process??😟😟
It will serve as bait... If it works and it gets executed, it'll over right the process I created(child process) and I'll still have my normal process(parent process) 🙊🙊🙊 OMG!!!! 
That would work🥹🥹🥹

'''

* I can create the child process using "fork()" 😉👉👌.... Nah!!! Not what you're thinking of 😂😂😂  'man it'

But if I'm going to be creating another process... My initial process will still be running... I won't want to create a """zombie process """ (read more in zombie and orphan process)🧟‍♀️🧟‍♂️

'''

Well, I know just how to slow the initial process 

'''

* Use "wait()" to let the parent process to wait 🥹😂. 

'''
Hmmm... This should help me with the mandatory tasks...😌😍🥰. There are lot of things to do to make all these work... I still need some more research... But now, I've got a thought process 🤪🫠... I know where I'm headed....

XL!!!
# Error
* memory leaks to be fixed from the main file!!!
## To be fixed!!!

## Fixed error!!!
