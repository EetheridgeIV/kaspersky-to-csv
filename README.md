# kaspersky-to-csv
Converts the export file from Kaspersky Password Manager, which is a .txt file, to a .csv file which can be used to import into 1password.

This only puts the "Websites" section from the .txt into csv format. Personally, I didn't have a lot in the "Applications" section so I'm just going to do that quickly manually.

https://support.1password.com/create-csv-files/

## To compile:
    make

## To run:
    ./ConvertToCSV <inputfile>

Program will create a CSV file named "1pass.csv" in the same directory you ran the program in.
