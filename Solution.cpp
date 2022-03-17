
#include <deque>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
    
    inline static const string DIRECTORY_SEPARATOR = "/";
    inline static const string CURRENT_DIRECTORY = ".";
    inline static const string DIRECTORY_UP_A_LEVEL = "..";

public:

    string simplifyPath(string path) {
        vector<string> elements;
        splitStringIntoVector(elements, path);
        deque<string> stackElements;

        for (const auto& element : elements) {
            if (element == CURRENT_DIRECTORY || element.empty()) {
                continue;
            }
            if (element == DIRECTORY_UP_A_LEVEL && stackElements.empty() == false) {
                stackElements.pop_front();

            } else if (element != DIRECTORY_UP_A_LEVEL) {
                stackElements.push_front(element);
            }
        }

        string simplifiedCanonicalPath;
        assembleSimplifiedCanonicalPath(simplifiedCanonicalPath, stackElements);

        return simplifiedCanonicalPath.empty() ? DIRECTORY_SEPARATOR : simplifiedCanonicalPath;
    }

private:

    void splitStringIntoVector(vector<string>& elements, const string& path) {
        const char delimeter = DIRECTORY_SEPARATOR[0];
        stringstream s(path);
        string element;
        while (getline(s, element, delimeter)) {
            elements.push_back(element);
        }
    }

    void assembleSimplifiedCanonicalPath(string& simplifiedCanonicalPath, deque<string>& stackElements) {
        while (!stackElements.empty()) {
            simplifiedCanonicalPath.append(DIRECTORY_SEPARATOR);
            simplifiedCanonicalPath.append(stackElements.back());
            stackElements.pop_back();
        }
    }
};
