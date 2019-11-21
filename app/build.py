import sys
import os

# Defining Usable Files
BUILD_FILE = "app.txt"
ICON_FILE_NAME = "file.png"

# Usable Icons
dirIcons = "Icon={0}/images".format(os.getcwd())
icon1 = "{0}/{1}\n".format(dirIcons, ICON_FILE_NAME)


def getNameOfApp(_file):
    """
    Get the name of the app from the file.
    return -> (fileRead, fRead, appName)
    """
    fileRead = open(_file, 'r')
    fRead = fileRead.readlines()
    appName = fRead[1].strip("Name=\n")

    return (fileRead, fRead, appName)


def makeFile():
    """
    Link output files and programs together.
    Append and link the App directory.
    """
    appExists = False
    (fileRead, fRead, appName) = getNameOfApp(BUILD_FILE)
  
    # If 'Exec' and 'Icons' can be found, app already exists

    if len(fRead) >= 6:
        appExists = True
        
    createApp = open("app/{0}.desktop".format(appName), 'w')
    defaultFile = open(BUILD_FILE, 'w')

    # If app doesn't exist, create files
    if not appExists:
        createFile(fRead, createApp, defaultFile, False)
    else: 
        createFile(fRead, createApp, defaultFile, True)

    # Close all files
    fileRead.close()
    defaultFile.close()
    createApp.close()
    
    
def createFile(fRead, createApp, defaultFile, default=True):
    """
    Append and Write new content to existing/valid 
    files.
    """ 
    # Write to files
    runCmd = "Exec=python3.6 {0}/run.py\n".format(os.getcwd().replace(' ', "_"))
    files = [createApp, defaultFile]
    for _file in files:
        if default:
            _file.writelines(fRead)
        else:
            _file.writelines(fRead)
            _file.write(runCmd)
            _file.write(icon1)


def remFile():
    """
    Remove all App's in directory.
    """
    cmd = "rm app/*.desktop"
    os.system(cmd)


def resetFile():
    """
    Reset the BUID File to it's default settings.
    """
    (fileR, contents, _) = getNameOfApp(BUILD_FILE)
    fileW = open(BUILD_FILE, 'w')

    # Write the default settings
    fileW.writelines(contents[:4])

    # Close all files
    fileW.close()
    fileR.close()


# Run script build.py
if __name__ == "__main__":
    # If arguments inputed with valid cmd, change info
    if len(sys.argv) > 1:
        fInput = sys.argv[1]
        if fInput == "build":
            makeFile()
        elif fInput == "remove":
            remFile()
            resetFile()
