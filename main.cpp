#include <iostream>
#include <string>
#include "./googletest/include/gtest/gtest.h"
namespace Chapters{
    using namespace std;
    class BankAccount{

    private:
        string name_;
        string account_;
        int deposit_;
    public:
        // 构造函数
        BankAccount(string name="pika", string account="123", int deposit=100){
            name_ = name;
            account_ = account;
            deposit_ = deposit;
        }

        // 显示储户姓名，账号，存款
        void PrintAccount(){
            cout << "name is " << name_ << '\n'
                 << "account is " << account_ << '\n'
                 << "deposit is " << deposit_ << endl;
        }

        // 存入参数指定的存款
        int SaveMoney(int money){
            deposit_ += money;
            cout << "存款成功！您的账户余额为：" << deposit_ << endl;
            return deposit_;
        }
        // 存入参数指定的存款
        bool DrawMoney(int money){
            if (deposit_ < money){
                cout << "取款失败，您的账户似乎没有那么多钱。。。" << endl;
                return false;
            }else{
                deposit_ -= money;
                cout << "存款成功！您的账户余额为"<< deposit_ << endl;
                return true;
            }
        }
    };
    class Person {
    private:
        //static const LIMIT = 25;
        string lname;
        char fname[25];
    public:
        Person() {lname = "admin"; fname[0] = '\0';  } // #1
        Person(const string & ln, const char* fn = "Heyyou"){
            lname = ln;
            strcpy(fname,fn);
        };
        // the following methods display lname and fname
        void Show() const{
            cout << fname << ' ' << lname << endl;
        };
        void FormalShow() const{
            cout << lname << ' ' << fname << endl;
        };
    };
    class BetelgeuseanPlorg {

    };
}


//TEST(chapters10, num1){
//    Chapters::BankAccount a("jojo","123",500);
//    a.PrintAccount();
//    EXPECT_EQ(a.SaveMoney(100), 600);
//    EXPECT_EQ(a.DrawMoney(400), true);
//    EXPECT_EQ(a.DrawMoney(1000), false);
//}

//TEST(chapters10, num2){
//    Chapters::Person one;
//    Chapters::Person two("Pika");
//    Chapters::Person three("Dim", "some");
//    // run
//    one.Show();
//    std::cout << std::endl;
//    one.FormalShow();
//
//    two.Show();
//    std::cout << std::endl;
//    two.FormalShow();
//
//    three.Show();
//    std::cout << std::endl;
//    three.FormalShow();
//    // end
//}

GTEST_API_ int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}