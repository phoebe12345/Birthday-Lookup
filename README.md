# Birthday-Lookup

Option 1: to load a birthday file – ask the user to input the name of the file containing birthday
information and load the entries from that file (report # of entries). Note that the file can be nonexistent (if so the program should print the error and keep running), but if it exists you can assume
the format inside that file is consistent (birthday, name, known-for), with each string at most 100
characters. it is possible for the user to load a different file by choosing this option again.

• Option 2: to list birthdays sorted by Month-Day – list the birthday entries from Jan 1 to Dec 31.
If a day has no entry, there is no need to print anything. If on that day there are more than one
birthday entry, any order within that day is acceptable.

• Option 3: to list birthdays sorted by Name – list the birthday entries sorted by name (as
determined by strcmp). If with the same name there are more than one birthday entry, any order
within that name is acceptable.

• Option 4: to lookup a birthday – ask the user for a month and then a day, then report all entries
with the same birthday (regardless of the year). There can be more than one entry on any day.
o If one or more entries are found, print all the information. Any order is acceptable.
o If no entry is found, print “No such birthday on record.”
There is no need to check if the input date is valid (e.g., 2-31 will just result in the no-entry case).

• Option 5: to terminate the program – thank the user and end the program.
