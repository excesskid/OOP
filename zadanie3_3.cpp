
#include <iostream> 
#include <memory>
int main() {
    {
        std::unique_ptr<int> a1 = std::make_unique<int>(88);
        std::cout << *a1 << "\n";    // Здесь delete не нужен — a1 сам освободит память
    }

    std::unique_ptr<int> a2 = std::make_unique<int>(77);
    std::cout << *a2 << "\n";
    std::unique_ptr<int> a3 = std::move(a2);
    std::cout << (a2 ? "alive" : "nullptr") << "\n";
    std::cout << "a3 value" << *a3 << "\n";
    //здесь я прото показал что а2 автоматически ставновится пустым когда его значение переходит к а3 это отличает умный указатель

    std::weak_ptr<int> o;

    {
        std::shared_ptr<int> r = std::make_shared<int>(99);
        o = r;
        std::cout << "r value : " << *r << "\n";

        // r.use_count() — сколько shared_ptr владеют объектом. (r только одним)
        std::cout << r.use_count() << "\n";

    }
    if (auto u = o.lock()) {
        std::cout << "обьект жив: " << *u << "\n";
    } else {
        std::cout << "обьект удален\n";
    }
    return 0;
}