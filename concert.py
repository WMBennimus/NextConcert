import sys
import json

if __name__ == "__main__":

    elFile = open(sys.argv[1]).read()
    data = json.loads(elFile)

    i = 1
    for concert in data:
        print("Concert #"+str(i)+":")
        print("  WHAT:")
        print("    "+concert["venue"]["name"])
        print("    "+concert["description"])
        print("  WHERE:")
        print("    "+concert["venue"]["street_address"])
        print("    "+concert["venue"]["location"]+" "+concert["venue"]["postal_code"])
        print("  WHEN:")
        print("    "+concert["datetime"].split('T')[0])
        print("    "+concert["datetime"].split('T')[1])
        print("")
        i = i + 1
