#!/bin/bash


clear
cd $HOME
echo "Enter a direcotry name:"
read directoryName
if [ -d $directoryName ]; then
	cd $HOME/$directoryName
else
	mkdir $directoryName
	cd $directoryName
fi
if [ -a $HOME/$directoryName/extractor.log ]; then
	if [ -a $HOME/$directoryName/Information ]; then
		echo "Information file already exists" > extractor.log
	else
		touch Information
		echo "Information file has been created" > extractor.log
	fi

else 
	touch extractor.log
	touch Information
	echo "Information file has been created" > extractor.log
fi
chmod 640 Information
echo "Access right changed for Information file" >> extractor.log
who | grep -o "\\w*[abcd]\\w*\s" > Information
echo "List of user names has been added to the Information file" >> extractor.log
echo -n "The number of found users is: "  >> extractor.log
who | grep -oc "\\w*[abcd]\\w*\s" >> extractor.log
echo "Execution of InformationExtractor script has ended successfully!"
