#include <array>
#include <string> 
#include <iostream>
#include <iomanip> 

class GradeBook {
public:
    static const size_t students = 5;
    static const size_t tests = 3;

    GradeBook(const std::string& name,
        std::array<std::array<int, tests>, students>& gradesArray)
        : courseName(name), grades(gradesArray) {
    }

    void setCourseName(const std::string& name) {
        courseName = name;
    }

    const std::string& getCourseName() const {
        return courseName;
    }

    void displayMessage() const {
        std::cout << "Welcome to the grade book for\n" << getCourseName() << "!" << std::endl;
    }

    void processGrades() const {
        outputGrades();

        std::cout << "\nLowest grade in the grade book is " << getMinimum()
            << "\nHighest grade in the grade book is " << getMaximum()
            << std::endl;

        outputBarChart();
    }

    int getMinimum() const {
        int min = 100;

        for (auto const& student : grades){
            for (auto const& grade : student) {
                if (grade < min)
                    min = grade;
            }
        }
        return min;
    }
        
    int getMaximum() const {
        int max = 0;

        for (auto const& student : grades){
            for (auto const& grade : student) {
                if (grade > max)
                    max = grade;
            }
        }
        return max;
    }
        
    double getAverage(const std::array<int, tests>& setOfGrades) const {
        int total = 0;

        for (int grade : setOfGrades)
            total += grade;

        return static_cast<double>(total) / setOfGrades.size();
    }
        
    void outputBarChart() const {
        std::cout << "\nOverall grade distribution:" << std::endl;
        const size_t freq = 11;
        std::array<unsigned int, freq> frequency{};
        for (auto const& student : grades) {
            for (auto const& test : student)
                ++frequency[test / 10];
        }
        for (size_t count = 0; count < freq; ++count){
            if (0 == count)
                std::cout << "  0-9: ";
            else if (10 == count)
                std::cout << "  100: ";
            else
                std::cout << count * 10 << "-" << (count * 10) + 9 << ": ";
            for (unsigned int stars = 0; stars < frequency[count]; ++stars)
                std::cout << '*';
            std::cout << std::endl;
        }
    }
        
    void outputGrades() const {
        std::cout << "\nThe grades are:\n\n";
        std::cout << "            ";
                
        for (size_t test{ 0 }; test < tests; ++test) {
            std::cout << "Test " << test + 1 << "  ";
        }

        std::cout << "Average" << std::endl;
                
        for (size_t student{ 0 }; student < grades.size(); ++student) {
            std::cout << "Student " << std::setw(2) << student + 1;
                    
            for (size_t test{ 0 }; test < grades[student].size(); ++test) {
                std::cout << std::setw(8) << grades[student][test];
            }
                        
            double average{ getAverage(grades[student]) };
            std::cout << std::setw(9) << std::setprecision(2) << std::fixed
                << average << std::endl;
        }
    }
private:
    std::string courseName;
    std::array<std::array<int, tests>, students>    grades;
};
