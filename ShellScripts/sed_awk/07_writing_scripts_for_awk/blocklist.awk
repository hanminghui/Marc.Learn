# blocklist.awk -- print name and address in block form
# input file -- namelist
# name, company, street, city, state and zip, phone
BEGIN { FS = "," }
{
	print "" # output the blank line
	print $1 # name
	print $2 # company
	print $3 # street
	print $4, $5 # city, state zip
	print $6 # phone
}
