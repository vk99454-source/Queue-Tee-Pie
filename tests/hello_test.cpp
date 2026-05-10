#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/hello.hpp"

class TestCutie : public Cutie {
private:
    string description;
    int rating;
public:
    TestCutie(string description, int rating) : Cutie(description, rating) {
        this->description = description;
        this->rating = rating;
    }
    string get_description() override {
        return description;
    }
    int get_cuteness_rating() override {
        return rating;
    }
};
TEST_CASE("queue starts empty") {
    QueueTees queue;
    REQUIRE(queue.size() == 0);
    REQUIRE(queue.dequeue() == nullptr);
}
TEST_CASE("enqueue adds items and dequeue removes in order") {
    QueueTees queue;
    TestCutie puppy("Puppy", 10);
    TestCutie kitty("Kitty", 9);
    queue.enqueue(&puppy);
    queue.enqueue(&kitty);
    REQUIRE(queue.size() == 2);
    Cutie* first = queue.dequeue();
    Cutie* second = queue.dequeue();
    REQUIRE(first->get_description() == "Puppy");
    REQUIRE(second->get_description() == "Kitty");
    REQUIRE(queue.size() == 0);
}
TEST_CASE("enqueue on full queue does not change size") {
    QueueTees queue;
    TestCutie c1("1", 1);
    TestCutie c2("2", 2);
    TestCutie c3("3", 3);
    TestCutie c4("4", 4);
    TestCutie c5("5", 5);
    TestCutie c6("6", 6);
    TestCutie c7("7", 7);
    TestCutie c8("8", 8);
    TestCutie c9("9", 9);
    TestCutie c10("10", 10);
    TestCutie c11("11", 11);
    queue.enqueue(&c1);
    queue.enqueue(&c2);
    queue.enqueue(&c3);
    queue.enqueue(&c4);
    queue.enqueue(&c5);
    queue.enqueue(&c6);
    queue.enqueue(&c7);
    queue.enqueue(&c8);
    queue.enqueue(&c9);
    queue.enqueue(&c10);
    queue.enqueue(&c11);
    REQUIRE(queue.size() == 10);
    Cutie* first = queue.dequeue();
    REQUIRE(first->get_description() == "1");
}