#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

struct Record {
    std::string name;
    int line;
    int count;
    Record() = default;
    Record(const std::string n, const int l) : name(n), line(l), count(1) {}
};

int main(int argc, char const *argv[]) {
    std::string file_path;
    int line_number;
    std::deque<Record> records;

    while (std::cin >> file_path >> line_number) {
        const auto index = file_path.find_last_of('\\');
        std::string raw_file_name = file_path.substr(index + 1);
        std::string file_name = raw_file_name.substr(std::max((int)(raw_file_name.length()) - 16, 0));
        const auto it = std::find_if(records.begin(), records.end(), [file_name, line_number](const Record& record) -> bool {
            return record.name == file_name && record.line == line_number;
        });
        if (it != records.end()) {
            ++it->count;
        } else {
            records.push_back(Record(file_name, line_number));
        }
    }

    while (records.size() > 8) {
        records.pop_front();
    }

    for (const Record& record: records) {
        std::cout << record.name << ' ' << record.line << ' ' << record.count << std::endl;
    }

    return 0;
}
