#include <iostream>
#include <string>
using namespace std;

class simple_test {
private:
    string full_name;
    string questions[3] = {
        "Do you like programming? (Yes/No): ",
        "Are you learning C++? (Yes/No): ",
        "Do you like tests? (Yes/No): "
    };
    int scores[3] = { 2, 3, 1 };
    int total_score = 0;

    bool check_full_name(const string& s) {
        for (char c : s) {
            if (!(isalpha((unsigned char)c) || c == ' ' || c == '.')) {
                return false;
            }
        }
        return true;
    }

    string to_lowercase(string str) {
        for (auto& c : str) {
            c = tolower((unsigned char)c);
        }
        return str;
    }

public:
    void input_full_name() {
        cout << "Enter your full name: ";
        getline(cin, full_name);

        if (!check_full_name(full_name)) {
            cout << "Error: invalid characters entered!" << endl;
            full_name = "";
        }
    }

    void run_test() {
        if (full_name.empty()) return;

        string answer;
        for (int i = 0; i < 3; i++) {
            cout << questions[i];
            cin >> answer;
            answer = to_lowercase(answer);
            if (answer == "yes") {
                total_score += scores[i];
            }
        }
    }

    void print_result() {
        if (!full_name.empty()) {
            cout << full_name << ", your result: " << total_score << " points" << endl;
        }
    }
};

class url_parser {
private:
    string url;
    string protocol;
    string domain;
    string path;
    string query;

public:
    url_parser(const string& u) {
        url = u;
    }

    void parse() {
        int pos = url.find("://");
        protocol = url.substr(0, pos);

        int pos2 = url.find("/", pos + 3);
        domain = url.substr(pos + 3, pos2 - (pos + 3));

        int pos3 = url.find("?", pos2);
        if (pos3 != string::npos) {
            path = url.substr(pos2, pos3 - pos2);
            query = url.substr(pos3 + 1);
        }
        else {
            path = url.substr(pos2);
            query = "";
        }
    }

    void print_parts() {
        cout << "Protocol: " << protocol << endl;
        cout << "Domain: " << domain << endl;
        cout << "Path: " << path << endl;
        cout << "Query: " << query << endl;
    }
};

int main() {
    simple_test test;
    test.input_full_name();
    test.run_test();
    test.print_result();

    cin.ignore();

    string url = "http://www.ufa.com.ua/utilites/hdd/out.php?sort=2";
    url_parser parser(url);
    parser.parse();
    parser.print_parts();

    return 0;
}
