How to open and create a compilable project.

Because of how CCS5 stores relative path names in a project, it is VERY important to put things exactly where specified here, otherwise you will get a lot of hard-to-diagnose errors about not being able to find either .cmd files or source files (.c, .h) from SimpliciTI.

Create a subdirectory called work somewhere.  I'll assume this is in your home folder.  Everything is referenced off of this directory.



Install SimpliciTI in the work folder.
Get SimpliciTI from http://www.ti.com/tool/simpliciti.  Make sure to get the one for CCS.  The version used in these instructions is 1.1.1.  Extract the .exe file installer anywhere, and run it.  The install destination folder MUST be set to the work directory, then SimpliciTI-CCS-1.1.1 (or whatever version you are using).  So for me, I set the Destination Folder during setup to C:\Users\jmanton\work\SimpliciTI-CCS-1.1.1.



Now get the code from SVN.
From within the work folder, in Windows Explorer, right click on listing of empty directory, and choose "svn checkout..." (this assumes you have TortoiseSVN installed)

The URL you will use is https://github.com/wsntopo/msp430.  Make sure to set the checkout directory to some subdirectory, if you use multiple different SVN repositories.  E.g., I would change my "Checkout directory:" to C:\Users\jmanton\work\msp430.





Start Code Composer Studio (these instructions assume CCS 5).  The workspace will be under that "work" directory, as msp430\trunk\CCS\CCS application.  For instance, for me it is C:\Users\jmanton\work\msp430\trunk\CCS\CCS application.  You will not see any files.  Strangely, you now have to "import" the project.  The files are in the same place, so don't copy the files.  It should just work (yeah, right).

Go to Project/Import Existing CCS Eclipse Project...
In the search directory, put in the same directory you used when setting your workspace.  E.g., for me, I put in C:\Users\jmanton\work\msp430\trunk\CCS\CCS application.  Do NOT click the copy projects or automatically import referenced projects.  Hit Finish.

Now you should see the files.  Set the build configuration to sleep-wake.  Right click on the SimpliciTI test folder in the top left, choose Build Configurations/Set Active/sleep-wake