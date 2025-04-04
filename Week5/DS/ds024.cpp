#include <iostream>
#include <sstream>
#include <fstream>
#define MAX 50

using namespace std;
string kname[2] = {"A+~F", "P/F"}; // String for grading

class MyClass{
private:
	int code;		    // class code
	string name; 	// class name
	int unit;		    // credits
	int grading;	    // grading category (1:A+~F, 2:P/F)
public:
    MyClass(int ncode, string nname, int nunit, int ngrading){
        code = ncode; name = nname; unit = nunit; grading = ngrading;
    }
    ~MyClass(){}
    int getCode(){ return code; }
    string getName(){ return name; }
    int getUnit(){ return unit; }
    int getGrading(){ return grading; }
    void setCode(int newcode){ code = newcode; }
    void setName(string newname){ name = newname; }
    void setUnit(int newunit){ unit = newunit; }
    void setGrading(int newgrading){ grading = newgrading; }

    string toString(){
        stringstream sstm;
        sstm << "[" << code << "] " << name << " [credit " << unit << " - " << kname[grading-1] << "]";
        return sstm.str();
    }

    string toStringSave(){
        stringstream sstm;
        sstm << code << " " << name << " " << unit << " " << grading;
        return sstm.str();
    }
};

class MyClassManager{
private:
    MyClass* allclasses[MAX];
    MyClass* myclasses[10];
    int count;
    int mycount;

public:
    MyClassManager(){
        count = 0;
        mycount = 0;
    }
    ~MyClassManager(){}

    int getCount(){ return count; }
    int getMyCount(){ return mycount; }

    void loadData(string filename);
    void printAllClasses();
    void findClasses(string name);
    void saveAllClasses(string filename);

    void addClass();
    void editClass();

    void applyMyClass();
    void printMyClasses();
    void saveMyClasses(string filename);
};

int main() {
	int no;
    int quit = 0;
	string name;

	MyClassManager manager;

	manager.loadData("classes.txt");

	while (!quit) {
		cout << "Menu 1.List 2.Add 3.Modify 4.Search 5.Apply 6.My classes 7.Save 0.Quit\n";
		cout << ">> Menu? > ";
		cin >> no;
        switch(no){
            case 1:
	    		cout << "> 1.Print All Classes\n";
	    		manager.printAllClasses();
                break;
            case 2:
	    		cout << "> 2.Add a Class\n";
    			manager.addClass();
                break;
		    case 3:
	    		cout << "> 3.Modify a Class\n";
    			manager.editClass();
                break;
            case 4:
			    cout << "> 4.Search a Class\n";
			    cout << ">> Enter class name > ";
			    cin >> name;
			    manager.findClasses(name);
                break;
		    case 5:
	    		cout << "> 5.Apply a class\n";
    			manager.applyMyClass();
		    	cout << manager.getMyCount() << " classes has been applied.\n";
                break;
    		case 6:
    			cout << "> 6.My classes\n";
	    		manager.printMyClasses();
                break;
    		case 7:
    			cout << "> 7.Save\n";
	    		manager.saveMyClasses("myclasses.txt");
		    	cout << "\n> All my classes were saved to my_classes.txt.\n";
			    manager.saveAllClasses("classes.txt");
			    cout << "\n> All of class list were saved to classes.txt.\n";
                break;
            case 0:
                quit = 1;
                break;
		}
	}
	return 0;
}

void MyClassManager::loadData(string filename){
    int code, unit, grading;
    string name;

    ifstream file(filename);
    if (!file) {
        cout << "파일을 열 수 없습니다: " << filename << endl;
        return;
    }

    while (file >> code >> name >> unit >> grading) {
        allclasses[count++] = new MyClass(code, name, unit, grading);
    }

    file.close();
    cout << count << " classes are loaded.\n";
}

void MyClassManager::printAllClasses(){
    for (int i = 0; i < count; i++) {
        cout << allclasses[i]->toString() << endl;
    }
}

void MyClassManager::saveAllClasses(string filename){
    ofstream file(filename);
    for (int i = 0; i < count; i++) {
        file << allclasses[i]->toStringSave() << endl;
    }
    file.close();
}

void MyClassManager::findClasses(string name){
    int found = 0;
    cout << "Searching keyword: " << name << endl;
    for (int i = 0; i < count; i++) {
        if (allclasses[i]->getName().find(name) != string::npos) {
            cout << allclasses[i]->toString() << endl;
            found++;
        }
    }
    cout << found << " classes found.\n";
}

void MyClassManager::addClass(){
    int code, unit, grading;
    string name;

    cout << ">> code number > ";
    cin >> code;

    for (int i = 0; i < count; i++) {
        if (allclasses[i]->getCode() == code) {
            cout << "> Code duplicated! Retry.\n";
            return;
        }
    }

    cout << ">> class name > ";
    cin >> name;
    cout << ">> credits > ";
    cin >> unit;
    cout << ">> grading (1: A+~F, 2: P/F) > ";
    cin >> grading;

    allclasses[count] = new MyClass(code, name, unit, grading);
    count++;
    cout << "> Class added successfully.\n";
}

void MyClassManager::editClass(){
    int code;
    cout << ">> Enter a code of class > ";
    cin >> code;

    int idx = -1;
    for (int i = 0; i < count; i++) {
        if (allclasses[i]->getCode() == code) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        cout << "> No such class.\n";
        return;
    }

    string name;
    int unit, grading;
    cout << "> Current: " << allclasses[idx]->toString() << endl;
    cout << ">> Enter new class name > ";
    cin >> name;
    cout << ">> Enter new credits > ";
    cin >> unit;
    cout << ">> Enter new grading (1:Grade, 2: P/F) > ";
    cin >> grading;

    allclasses[idx]->setName(name);
    allclasses[idx]->setUnit(unit);
    allclasses[idx]->setGrading(grading);
    cout << "> Modified.\n";
}

void MyClassManager::applyMyClass(){
    int code;
    int more = 1;

    while (more == 1) {
        cout << ">> Enter a class code > ";
        cin >> code;

        int found = -1;
        for (int i = 0; i < count; i++) {
            if (allclasses[i]->getCode() == code) {
                found = i;
                break;
            }
        }

        if (found == -1) {
            cout << "> No such code of class.\n";
        } else {
            bool already = false;
            for (int j = 0; j < mycount; j++) {
                if (myclasses[j]->getCode() == code) {
                    already = true;
                    break;
                }
            }

            if (already) {
                cout << "> Already applied.\n";
            } else {
                myclasses[mycount++] = allclasses[found];
                cout << "> [" << allclasses[found]->toString() << "]\n";
            }
        }

        cout << ">> Add more?(1:Yes 2:No) > ";
        cin >> more;
    }
}

void MyClassManager::printMyClasses(){
    int total = 0;
    for (int i = 0; i < mycount; i++) {
        cout << i + 1 << ". " << myclasses[i]->toString() << endl;
        total += myclasses[i]->getUnit();
    }
    cout << "All : " << total << " credits\n";
}

void MyClassManager::saveMyClasses(string filename){
    ofstream file(filename);
    int total = 0;
    int af = 0, pf = 0;

    file << "My Classes\n";
    for (int i = 0; i < mycount; i++) {
        file << i + 1 << ". " << myclasses[i]->toString() << endl;
        total += myclasses[i]->getUnit();
        if (myclasses[i]->getGrading() == 1) af += myclasses[i]->getUnit();
        else pf += myclasses[i]->getUnit();
    }

    file << "All : " << mycount << " classes, " << total << " credits (A+~F " << af << " credits, P/F " << pf << " credits)\n";
    file.close();
}