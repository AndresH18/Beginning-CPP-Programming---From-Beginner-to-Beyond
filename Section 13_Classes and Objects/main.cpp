#include <iostream>
#include <vector>

#include "Account.h"
#include "Player.h"

using namespace std;


class Move {
private:
    int *data;
public:
    void set_data_value(int d) { *data = d; }

    int get_data_value() { return *data; }

    Move(int d) {
        data = new int;
        *data = d;
    }

    Move(const Move &source) {
        data = new int;
        *data = *source.data;
    }

    Move(Move &&source) : data{source.data} {
        source.data = nullptr;
    }


    ~Move() {
        delete data;
    }

};


int main() {
    cout << boolalpha;
    /**
     * class Class_Name
     * {
     *      // declarations(s);
     * };
     *
     * class Player
     * {
     *      // atributes
     *      std::string name;
     *      int health;
     *      int xp;
     *
     *      // methods
     *      void talk(std::string text_to_say);
     *      bool is_dead();
     * };
     *
     * Player frank;
     * Player hero;
     *
     * Player *villain = new Player();
     * delete villain;
     *
     * std::vector<Player> players {frank, hero};
     * players.push_back(*villain};
     * Player mPlayer[] {frank, hero, villain};
     *
     *
     **Access Attributes and Methods
     * By default, all information inside of a class (atributes and methods) are private.
     * So in order to make attributes public, we need to say:
     * *
     * public:
     * //attributes
     *
     * Everything that is after the "public:" is going to be public
     *
     * using the . operator
     * *
     * Account account;
     * account.balance;
     *
     * Account *mAccount = new Account;
     * (*mAccount).balance;
     *
     * Using the member pointer operator (arrow operator)
     * *
     * Account *account = new Account();
     * account -> balance;
     *
     *
     * Class Member Access Modifiers
     * Everything below the access modifier is applied that modifier, until another acces modifier
     * By default, every member of the class is private.
     * public:
     *  accessible everywhere
     *
     * private:
     *  accessible only by members or friends of the class
     *
     * protected:
     *  used with inheritance
     *
     * *
     * class Class_Name
     * {
     *  public:
     *      // declaration(s);
     *  private:
     *      // declaration(s);
     * };
     *
     */

    /** Implement Member Methods
    * -    Very similar to how we implemented functions.
    * -    Member methods have access to member attributes.
    *          so you dont need to pass them as arguments.
    * -    Can be implemented inside the class declaration.
    *          Implicitly inline.
    * -    Can be implemented outside the class declaration.
    *          Need to use Class_Name::method_name .
    * -    Can separate specification from implementation.
    *          .h or .hpp file for the class declaration.
    *          .cpp file for the class implementation.
    *
    * * inside class declaration
    * class Account
    * {
    *  private:
    *      double balance;
    *  public:
    *      void set_balance(double bal) {
    *          balance = bal;
    *      }
    * };
    *
    * * outside class declaration
    * class Account
    * {
    *  private:
    *      double balance;
    * public:
    *  void set_balance(double balance);
    * };
    *
    * void Account::set_balance(double balance) {
    *      balance = bal;
    * }
    *
    * CHECK Account.h, Account.pp
    *
    * Always include .h files, not .cpp
    ************ ALWAYS INCLUDE .h FILES, NOT .cpp
    *
    *
    *** Constructors and Destructors
    *
    * Constructors
    * * Special member method
    * * Invoked during object creation
    * * Useful for initialization
    * * Same name as the class
    * * No return type is specified
    * * Can be overloaded
    *
    * Destructors
    * * Special member method
    * * Same name as the class preceded with a ~
    * * Invoke automatically when an object is destroyed
    * * No return type and no parameters
    * * Only 1 destructor is allowed per class - cannot be overloaded!
    * * Useful to release memory and other resources
    *
    *
    */

    Player hero; // empty constructor
    Player enemy{"minion"}; // constructor called

    cout << "The hero xp is " << hero.xp << endl;
//    cout << "The hero health is " << hero.health; // Error, Player.health is private by default
    enemy.xp = 1000;

    Player players[]{hero, enemy};

    vector<Player> player_vector{hero};
    player_vector.push_back(enemy);

    Player *villain{nullptr};
    villain = new Player{"Andres", 10000, 10000};
    player_vector.push_back(*villain);


    villain->damage(150);
    cout << "Is villain dead? " << villain->is_dead() << endl;


    delete villain; // destructor called

    Account andres_account;
    andres_account.set_balance(10000);

    cout << "The balance in the account is: " << andres_account.get_balance() << endl;

    /**
     * CONSTRUCTOR INITIALIZATION LISTS
     *
     * Are more efficient
     * Initialization list immediately follows the parameter list
     * Initializes the data members as the object is created
     * Order of initialization is the order of declaration in the class
     *
     * *
     * Player::Player() : name{"playerName"}, health{100}, xp{0} {
     * }
     *
     * Player::Player(std::string name_val) : name{name_val}, health{100}, xp{0} {
     * }
     *
     * Player::Player(std::string name_val, int health_val, int xp_val) : name{name_val}, health{health_val}, xp{xp_val} {
     * }
     *
     *
     * Delegating Constructors
     * Calling other constructor of the same class inside a constructor
     * *
     *  PLayer::Player(std::string name_val, int health_val, int xp_val)
     *      : name{name_val}, health{health_val}, xp{xp_val} {
     *  }
     *  Player::Player() : Player {"No name", 0, 0} {
     *  }
     *  Player::Player(std::string name_val) : Player {name_val, 0, 0} {
     *  }
     *
     *  We can also use default values in constructors
     *
     *
     * COPY CONSTRUCTOR
     * *When objects are copied c++ must create a new object from an existing object
     * *When is a copy of an object made?
     *  - passing object by value as a parameter
     *  - returning an object from a function by value
     *  - constructing one object base on another of the same class
     *
     * *C++ must have a way of accomplishing this so it provides a compiler defined copy constructor if you don't
     *
     * *
     * void do_something(Player p) {
     *      // p is a COPY of hero in this example
     *      // use p
     *      //Destructor for p will be called, because the method ended
     * }
     * *
     * Player create_super_enemy() {
     *      Player super_enemy{};
     *      return super_enemy{}; // A COPY of super_enemy is returned
     * }
     * *
     * Player enemy1;
     * Player enemy2 {enemy}; // a COPY of enemy1 is made
     *
     * If you don't provide a way to copying object, the compiler provides a default way
     *
     * Copies the value of each data member to the new object
     *      default member-wise copy
     *
     * Perfectly fine in many cases(default copy constructor)
     *
     * Beware if you have a pointer dataa member
     *      pointer will be copied
     *      Not what it is pointing to
     * Shallow vs deep copy
     * ------------------------------------------------
     * Best Practices
     * -Provide a copy constructor when your class has raw pointer members
     * -Provide the copy constructor with a const reference parameter
     * -Use STL classes as they already provide copy constructors
     * -Avoid using raw pointer data members if possible
     *
     * *
     * // the source keyword helps so we don't change anything by mistake
     * Type::Type(const Type $source);
     * Player::Player(const Player &source);
     * Account::Account(const Account &source);
     *
     *
     * Shallow copies are dangerous with pointers, because you end with 2 pointer pointing to the same memory location
     * so if one of the objects is destroyed, you still have a pointer to some data.
     * That is why when using pointers, one must do a DEEP COPY
     *
     * There is also the risk when passing objects as arguments, since when the block ends the destructor is called.
     * This can caused that data on the heap is liberated, but the original object is still pointing to it
     *
     */


     
    /**
     * MOVE CONSTRUCTOR
     * Sometimes when code is executed the compiler creates unnamed temporary variables.
     * *
     * int total{0};
     * total = 100 + 200;
     * *
     * 300 is stored in an unnamed temo value.
     * Then it's stored in the variable total.
     * Then the temp value is discarded.
     *
     * r-Value references
     * *
     * int x{100};
     * int & l_ref = x;     // l-value reference
     * l_ref = 10;          // change x to 10
     *
     * int && r_ref = 200;  // r-value ref
     * r_ref = 300;         // change r_ref to 300
     *
     * int && x_ref = x;    // Compiler error
     * *
     * int x {100};         // x is an l-value
     * void func(int &num); // A
     * func(x);         // calls A - x is an l-value
     * func(200);       // Error - 200 is an r-value
     * *
     * int x {100};         // x is an l-value
     * void func(int &&num); // B
     * func(200);       // calls B - 200 is an r-value
     * func(x);         // Error - x is an l-value
     *
     * *
     * Type::Type(Type &&source);
     * Player::Player(Player &&source);
     * Move::Move(Move &&source) : data{source.data} {
     *      source.data = nullptr;
     * }
     *
     * **ES MUY IMPORTANTE HACER QUE EL POINTER DE LOS DATOS DE SOURCE NULL
     * VER LA CLASE MOVE
     */

    for(int i{0}; i < 10; ++i) {

    }


    return 0;


}
