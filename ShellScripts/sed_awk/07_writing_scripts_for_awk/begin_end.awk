BEGIN { print "before the input is read" }
BEGIN { print "==================================================" }
{ print }
END { print "==================================================" }
END { print "before the input is read" }
