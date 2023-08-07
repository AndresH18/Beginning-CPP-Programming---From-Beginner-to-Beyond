//
// Created by andre on 6/8/2021.
//

#ifndef SECTION_13_CLASSES_AND_OBJECTS_DEEP_COPY_H
#define SECTION_13_CLASSES_AND_OBJECTS_DEEP_COPY_H


class Deep_Copy {
private:
    int *data;

public:
    Deep_Copy(int d); // constructor
    Deep_Copy(const Deep_Copy &source); // Copy-Constructor
    Deep_Copy(Deep_Copy &&copy);

    ~Deep_Copy();

};


#endif //SECTION_13_CLASSES_AND_OBJECTS_DEEP_COPY_H
