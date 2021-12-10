#include <string>
#include <utility>
#include <exception>
using namespace std;
class arrayException : public exception {
private:
    string exceptionText;
public:
    explicit arrayException(string error) : exceptionText(move(error)) {};
    [[nodiscard]] const char* what() const noexcept override { return exceptionText.c_str(); }
};