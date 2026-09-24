#Pair Programming

#Driver: Fibi Shoukry (U43930747)
#Navigator: Diya Jain (U81673988)

#This program displays all of the course information using a course number

#get values
courses = ('COP 2510', 'EGN 3000L', 'MAC 2281', 'MUH 3016', 'PHY 2048')
coursename = {'COP 2510': 'Programming Concepts', 'EGN 3000L': 'Foundations of Engineering Lab', 'MAC 2281': 'Calculus I', 'MUH 3016': 'Survey of Jazz', 'PHY 2048': 'General Physics I'}
instructor = {'COP 2510': 'S. Small', 'EGN 3000L': 'J. Anderson', 'MAC 2281': 'A. Makaryus', 'MUH 3016': 'A. Wilkins', 'PHY 2048': 'G. Pradhan'}
classtimes = {'COP 2510': 'MW 12:30pm - 1:45pm', 'EGN 3000L': 'TR 11:00am - 12:15pm', 'MAC 2281': 'MW 9:30am - 10:45am', 'MUH 3016': 'online asynchronous', 'PHY 2048': 'TR 5:00pm - 6:15pm'}

#computation and displaying results
coursenumber = input('Enter a course number: ')
if coursenumber == courses[0]:
    print('The course details are:\nCourse Name:', coursename['COP 2510'], '\nInstructor:', instructor['COP 2510'], '\nClass Times:', classtimes['COP 2510'])
elif coursenumber == courses[1]:
    print('The course details are: \nCourse Name:', coursename['EGN 3000L'], '\nInstructor:', instructor['EGN 3000L'], '\nClass Times:', classtimes['EGN 3000L'])
elif coursenumber == courses[2]:
    print('The course details are: \nCourse Name:', coursename['MAC 2281'], '\nInstructor:', instructor['MAC 2281'], '\nClass Times:', classtimes['MAC 2281'])
elif coursenumber == courses[3]:
    print('The course details are: \nCourse Name:', coursename['MUH 3016'], '\nInstructor:', instructor['MUH 3016'], '\nClass Times:', classtimes['MUH 3016'])
elif coursenumber == courses[4]:
    print('The course details are: \nCourse Name:', coursename['PHY 2048'], '\nInstructor:', instructor['PHY 2048'], '\nClass Times:', classtimes['PHY 2048'])
else:
    print(coursenumber, 'is an invalid course number.')
