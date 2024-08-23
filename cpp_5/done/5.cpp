#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class GameAccount {
   private:
    string playerID;
    string account;
    unordered_map<int, int> inventory;

   public:
    GameAccount(string id, string acc) : playerID(id), account(acc) {}

    void printAccountInfo() const {
        cout << "ID: " << playerID << endl;
        cout << "账号: " << account << endl;
        cout << "库存:" << endl;
        for (const auto& game : inventory) {
            cout << "游戏库存: " << game.first << ", 库存数量: " << game.second
                 << endl;
        }
    }
    void addgame(int name, int num) {
        inventory[name] += num;
        return;
    }

    void deletegame(int name, int num) {
        auto it = inventory.find(name);
        if (it != inventory.end()) {
            if (it->second >= num) {
                it->second -= num;
            } else {
                cout << "玩家库存数量不够";
            }
        } else {
            cout << "玩家没有这个游戏";
        }
    }
};
int main() {
    GameAccount account("12345", "player_one");
    account.printAccountInfo();

    account.addgame(101, 5);
    account.addgame(202, 3);
    cout << "加完一些库存" << endl;
    account.printAccountInfo();

    account.deletegame(101, 2);
    account.deletegame(303, 1);  // 尝试删除不存在的游戏
    account.deletegame(101, 5);  // 不够
    return 0;
}