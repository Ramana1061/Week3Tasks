#include <iostream>
#include <queue>
#include <random>
#include <chrono>
#include <thread>

using namespace std;

enum class EventType {
    TAP,
    SWIPE
};

class Event {
public:
    EventType eventType;
    int x, y;
    long long timestamp;

    Event(EventType type, int x, int y)
        : eventType(type), x(x), y(y) {
        timestamp = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
    }
};

class EventQueue {
private:
    queue<Event> eventQueue;

public:
    void pushEvent(const Event& event) {
        eventQueue.push(event);
    }

    bool hasEvents() {
        return !eventQueue.empty();
    }

    Event popEvent() {
        if (hasEvents()) {
            Event e = eventQueue.front();
            eventQueue.pop();
            return e;
        }
        throw runtime_error("No events to pop.");
    }
};

class EventHandler {
public:
    void processEvent(const Event& event) {
        if (event.eventType == EventType::TAP) {
            cout << "Tap detected at position (" << event.x << ", " << event.y << ").\n";
        }
        else if (event.eventType == EventType::SWIPE) {
            handleSwipe(event);
        }
    }

private:
    void handleSwipe(const Event& event) {
        string direction;
        if (event.x > 500) {
            direction = "Right";
        } else if (event.x < 100) {
            direction = "Left";
        } else if (event.y > 500) {
            direction = "Down";
        } else if (event.y < 100) {
            direction = "Up";
        }
        cout << "Swipe detected in the " << direction << " direction.\n";
    }
};

void generateRandomEvents(EventQueue& eventQueue) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> xDist(0, 800);
    uniform_int_distribution<> yDist(0, 600);
    uniform_int_distribution<> eventTypeDist(0, 1);  // 0 for TAP, 1 for SWIPE

    for (int i = 0; i < 10; ++i) {
        int x = xDist(gen);
        int y = yDist(gen);
        EventType type = (eventTypeDist(gen) == 0) ? EventType::TAP : EventType::SWIPE;
        Event event(type, x, y);
        eventQueue.pushEvent(event);

        this_thread::sleep_for(chrono::milliseconds(500));  // Simulate some delay between events
    }
}

int main() {
    EventQueue eventQueue;
    EventHandler eventHandler;

    // Generate random events and populate the queue
    generateRandomEvents(eventQueue);

    // Process events from the queue
    while (eventQueue.hasEvents()) {
        Event event = eventQueue.popEvent();
        eventHandler.processEvent(event);
        this_thread::sleep_for(chrono::milliseconds(300));  // Simulate time between event processing
    }

    return 0;
}
