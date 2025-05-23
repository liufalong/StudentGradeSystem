void GradeSystem::addStudent() {
    Student s;
    cout << "Enter student name: ";
    cin >> s.name;
    // 验证学号唯一性
    string id;
    bool idExists;
    do {
        idExists = false;
        cout << "Enter student ID: ";
        cin >> id;
        for (auto& student : students) {
            if (student.id == id) {
                cout << "ID already exists! Please enter a unique ID." << endl;
                idExists = true;
                break;
            }
        }
    } while (idExists);
    s.id = id;
    // ...其余代码...
}
void GradeSystem::deleteStudent() {
    string id;
    cout << "Enter student ID to delete: ";
    cin >> id;
    auto it = remove_if(students.begin(), students.end(),
        [&id](const Student& s) { return s.id == id; });

    if (it != students.end()) {
        students.erase(it, students.end());
        cout << "Student deleted successfully!" << endl;
    }
    else {
        cout << "Student not found!" << endl;
    }
}