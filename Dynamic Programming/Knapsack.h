using namespace std;

class Knapsack {
    public:
        Knapsack(int capacity);
        ~Knapsack();
        int getCapacity();
        void setCapacity(int capacity);

    private:
        int capacity;
};