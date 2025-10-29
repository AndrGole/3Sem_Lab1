#pragma once

#include <iostream>
#include <fstream>

struct QueueElement {
	std::string value;
	QueueElement* next;
};

//QueueElement* nullQueueElement = new QueueElement{ "", nullptr };

struct Queue {
	QueueElement* top;
	QueueElement* tail;
};

void createQueue(Queue* queue, std::string value);

void QueuePush(Queue* queue, std::string value);

QueueElement* QueuePop(Queue* queue);

std::ostream& operator<< (std::ostream& os, Queue queue);

std::ostream& operator<< (std::ostream& os, QueueElement* queueElement);

void exportQueue(Queue queue, std::string path);

Queue* importQueue(std::string path);