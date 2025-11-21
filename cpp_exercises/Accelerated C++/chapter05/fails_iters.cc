#include <vector>
#include "Student_info.h"
#include "grade.h"

using std::vector;

// version 3: iterators but no indexing; still potentially slow
vector<Student_info> extract_fails(vector<Student_info>& students)
{
	vector<Student_info> fail;
#ifdef _MSC_VER
	std::vector<Student_info>::iterator iter = students.begin();
#else
	vector<Student_info>::iterator iter = students.begin();
#endif

	while (iter != students.end()) {
		if (fgrade(*iter)) {
			fail.push_back(*iter);
			iter = students.erase(iter);
		} else
			++iter;
	}
	return fail;
}

The quick brown fox
Jumped over the fence

  quick     brown fox The
Jumped over the fence

The quick brown fox
Jumped over the fence


            quick     brown fox The 
             over     the fence Jumped 
                      brown fox The quick 
                      the fence Jumped over 
    fox The quick     brown 
fence Jumped over     the 
        The quick     brown fox 
      Jumped over     the fence 
            quick     brown fox The 
             over     the fence Jumped
             
             
             
   quick brown    fox The 
    over the    fence Jumped 
         brown    fox The quick 
         the    fence Jumped over 
         
quick brown

fox The quick brown

 fence Jumped over the