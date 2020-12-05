#include <iostream>
#include <string>
#include <vector>
#include <regex>

std::regex rx(R"(-?\d+)"); // По этим регистрам мы будем вычленять из строки числа
int main() {
    std::string input;
    std::vector<long> vec; //Вектор, куда пихаем эти числа (лонг, памушта там будут большие)
    size_t counter = 0;
    long long sum = 0;

    while(true){
        std::getline(std::cin, input); //строку взял
        if(input == ""){ //пустая?
            if(counter == 2){ //осторожно молодой человек с ентерами
                break; // попавсь, пока
            }
            counter++;// в этот раз предупреждение, соберешь 3 - бан
            continue; // делать тут больше нечего
        }
        std::smatch m; // я не ебу что это так на стак овер флоу дали
        std::string str = input; // ну инпут
        while (regex_search(str, m, rx)) { // Тоже не ебу какой то магический цикл который все делает
            vec.push_back(std::stol(m.str())); //помещаем число в вектор
            str = m.suffix().str();  //как я понял, идем дальше искать числа
        }
        counter = 0; // ну так как даже если уже счетчик был 2, но тип дальше попалось число, ну все, все штрафы сняли
    }
    for (auto& n : vec) //тут просто все суммируем и выводим
        sum += n;
    std::cout << sum;
    return 0;
}
