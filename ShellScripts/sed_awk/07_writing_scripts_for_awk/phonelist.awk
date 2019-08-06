# phonelist.awk -- print name and phone number
# input file -- namelist
# name, company, street, city, state and zip, phone
BEGIN { FS = "," }
{
	print "" # output the blank line
	print $1 ", " $6
}
END { print ""
	  print NR, "records processed." }
