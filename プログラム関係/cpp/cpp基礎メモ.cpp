cpp勉強会

初回10/27

必須includeは <iostream>,文字列使うときは<string>

::	スコープ解決演算子。 名前空間::cpp関数名のように使い、その関数がどこで定義されたものかを示す。cの.hファイル内の関数ならいらない。 ::関数名のように、前者がグローバル空間の場合もあるとか。 pythonでいうprint関数とかがはいってるのがstd空間。
std::cout << "hogehuga"; printしたり(改行したいなら<<std::endlを)
std::cerr coutと違って即時表示。エラーの表示に。
std::vector<型名>変数名  配列生成
std::cin >> banana; でコンソール入力ができる？
std:: string text = "hoge"; で文字を格納し、text objectに対しクラス内に定義してある関数が使えるようにex) text.length(); ←"4"として振る舞う

メイン関数の引数   int main(int argc, char* argv[]) 実行時のコマンドライン引数がそれぞれに入る。./hoge --ros-args -p param:=value なら、前者は4,後者にはargv[0]~[3]に--ros-argsやらが入る。

int floatじゃなくてautoで勝手に型を判断させることもできる

クラスの書き方      ちなクラス内の関数とか変数はメンバメソッドとかメンバ変数と呼ぶ
↓↓↓おおまかな構成↓↓↓
privateのなか...クラス内で使いたい変数を宣言
publicのなか...最初にインスタンス化につかう関数(コンストラクタ)を書く。クラスの名前(変数達)で。
		このなかで引数をprivateで定義した変数に格納、コンストラクタ外でもつかえるように。
		あとは好きにメソッドを記入。内部の変数を参照できる関数、ゲッター関数はとりあえず書かれがち?
↓↓↓具体例↓↓↓
		
class Student {
private:  //外からアクセスされたくない変数を書く
    // メンバ変数（属性）
    std::string name;
    int age;
    float gpa;

public:
    // コンストラクタ（オブジェクト作成時に呼ばれる）
    Student(std::string n, int a, float g) {
        name = n;
        age = a;
        gpa = g;
        std::cout << name << "のオブジェクトが作成されました！" << std::endl;
    }

    // メンバ関数（機能）
    void introduce() {
        std::cout << "私は" << name << "、" << age << "歳です。GPA: " << gpa << std::endl;
    }

    void study() {
        gpa += 0.1;
        std::cout << name << "が勉強しました！新しいGPA: " << gpa << std::endl;
    }

    // ゲッター
    std::string getName() { return name; }
    int getAge() { return age; }
    float getGpa() { return gpa; }

    // セッター
    void setGpa(float newGpa) {
        if (newGpa >= 0.0 && newGpa <= 4.0) {
            gpa = newGpa;
        } else {
            std::cout << "無効なGPA値です" << std::endl;
        }
    }
};

// メイン関数
int main() {
    // クラスからオブジェクトを作成（インスタンス化）
    Student student1("田中太郎", 20, 3.5);
    Student student2("佐藤花子", 19, 3.8);

    // メンバ関数の呼び出し
    student1.introduce();
    student2.introduce();

    student1.study();
    student2.study();

    // ゲッターで情報取得
    std::cout << student1.getName() << "の年齢: " << student1.getAge() << std::endl;

    // セッターで安全に変更
    student1.setGpa(3.9);
    student1.setGpa(5.0);

    return 0;
}
