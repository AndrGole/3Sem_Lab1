#include "Queue.h"

void createQueue(Queue* queue, std::string value) {
	queue->top = new QueueElement{ value, nullptr };
	queue->tail = queue->top;
}

void QueuePush(Queue* queue, std::string value) {
	QueueElement* newElement = new QueueElement{ value, nullptr };
	queue->tail->next = newElement;
	queue->tail = newElement;
}

QueueElement* QueuePop(Queue* queue) {
	// выводить элемент
	QueueElement* deleteElement = queue->top;
	queue->top = deleteElement->next;
	QueueElement* result = new QueueElement{deleteElement->value, nullptr};
	delete deleteElement;
	return result;
}

std::ostream& operator<< (std::ostream& os, Queue queue) {
	while (true) {
		if (queue.top->next == nullptr) {
			os << queue.top->value;
			break;
		}
		os << queue.top->value << " ";
		queue.top = queue.top->next;
	}
	return os;
}

std::ostream& operator<< (std::ostream& os, QueueElement* queueElement) {
	os << queueElement->value;
	return os;
}

void exportQueue(Queue queue, std::string path) {
	std::ofstream out;
	out.open(path);
	if (out.is_open()) {
		out << queue;
	}
	out.close();
}

Queue* importQueue(std::string path) {
	Queue* result = new Queue;
	std::ifstream in;
	in.open(path);
	if (in.is_open()) {
		std::string data;
		in >> data;
		createQueue(result, data);
		while (in >> data) {
			QueuePush(result, data);
		}
	}
	in.close();
	return result;
}