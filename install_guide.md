##Prerequisites
- Windows system
	- Most Windows systems can run this fine, unless you have a really low-end laptop.
	- OS: Windows 7 and up
	- Administrator access to the computer
- Programs
	- Microsoft Visual Studio (2010+)
	- or other Compiler and Editor as you prefer. If you prefer not to use Visual Studio, Sublime is a good subtitute along with DevCPP.

##Installation
General note: There are two different way to download and contribute to this repo, it is ultimately up to you to choose which one. Each way has its own advantage and disadvantage.
	
##Easy to download, hard to upload
[Click here](https://github.com/TenzoNakami/ARPKA) and find in top right the "Clone or download" button. Simply click and choose download ZIP. Extract and the code is ready to use.

Committing changes should be done manually as there is no way to upload your code directly to GitHub. Whenever there are changes committed to the repo, you will also need to re-download the whole ZIP again.

##Hard to setup, easy on later
[Click here](https://git-scm.com/downloads) and download the Windows installer.

**NOTE:** The installation process of Git has to go exactly as described below, otherwise you will have to take longer ways around!

Once downloaded, run the installer. Read the license and continue. Once you get to the component selection, *make sure that it looks at least like this!*

![Component selection](https://s12.postimg.org/a0mn10p31/gitsetup1.png)

After selecting the start menu folder, this is where things get precise. **Make sure that you tick the boxes exactly as follows!**

![Git 1](https://s15.postimg.org/pvrcwsjor/2016_11_06_11_58_39_Git_2_10_2_Setup.png)
![Git 2](https://s10.postimg.org/7mutp1gmx/gitsetup3.png)
![Git 3](https://s10.postimg.org/auzb232wp/gitsetup4.png)
![Git 4](https://s10.postimg.org/e33sf4p6h/gitsetup5.png)

**And in text:**  
`Use Git from the Windows Command Prompt` (In *Adjusting your PATH environment*)  
`Checkout Windows-style, commit Unix-style endings` (In *Configure the line ending conversions*)  
`Use OpenSSH`(In *Choosing the SSH executable*)  
`Use MinTTY (the default terminal MSYS2)` (In *Configuring the terminal emulator to use with Git Bash*)  
When you've gotten that straight, **you've set up Git in the way we intend to use it!**		

Next, we'll retrieve the ARPKA GitHub repository, or clone in Git terms. This means that we download the bot using the Git SCM system. Now, you might ask: *Why are we doing this? Can't I just download a ZIP package?*  
The answer is: No. We're making it easier for you in the future to update and commit changes, just follow along for now.

You'd want to figure out where you want the bot to be downloaded. Something simple like the root of the C:\ drive (Possibly some other drive, though **NOT A FLASH DRIVE**) or optionally your Desktop could be fine.
When you've found the location of your choice, hit Shift+Right click and select `Git Bash here`. This will open the Git Bash console.
Type the following command into Git Bash:
```bash
git clone https://github.com/TenzoNakami/ARPKA -b master
```
Let it clone the Git repository. You have now successfully cloned the ARPKA Git repository!

##Updating and Committing changes using the Git Bash
When updating the bot, run the following command in CMD (Windows) or console (Linux) with the working directory pointed to the ARPKA folder:
```
git pull
```

Go to the main folder (the folder when you can see readme.MD) and hit Shift+Right click and select `Git Bash here`. Type the following command into Git Bash:
```bash
git add .
```

and then:
```bash
git commit -m "your_name"
```

don't forget to change the your_name part with Your real name.

When it's done, time to upload the files:
```bash
git push
```

It should ask for your credentials, just fill it in and you're good.
Always re-check on the repository if your update has been pushed or not.