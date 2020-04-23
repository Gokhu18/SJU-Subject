#include "perceptron.h"
#include "activation_function.h"
using namespace std;

Perceptron::Perceptron(
	int input_size,
	string activation_function = "sigmoid")
{
	input_size_ = input_size;
	weight_initialized_ = false;
	inputdata_exist_ = false;

	// �̷��� �ۼ�Ʈ�и��� ���� �Ҵ�޾Ƽ� ����ϰ� �ȴٸ�, 
	// ��� �����͸� �� �����ؼ� ����ؾ� �� �� ���Ƽ� �ӽ��ּ�.
	// �ּ� ������ �� ��!!!
//	input_ = new double[input_size]; 

	// ��� weight �� �ۼ�Ʈ�� �ȿ� ���� �ʿ�� ���ٰ� �����ϴµ�
	// ��� �ϸ� ������ ���...
	weights_ = new double[input_size];
	set_activation_function(activation_function);
}

Perceptron::~Perceptron()
{
//	delete[] input_;
	delete[] weights_;
}

Activations Perceptron::activations_;


void Perceptron::set_activation_function(
	string activation_function)
{
	if (activation_function == "sigmoid")
	{
		activation_function_ = activations_.get_sigmoid();
	}
	else
	{
		cout << "activation function not defined error!" << endl;
	}
}

void Perceptron::ShowAllForDebug() const
{
	cout << "=======about perceptron=======\n" << endl;
	cout << "weight initialized? : " << (IsWeightInitialized() == true ? "yes" : "no") << endl;
	cout << "input size : " << get_input_size() << endl;
	cout << endl;

	if (IsInputdataExist()) 
	{
		cout << "-------perceptron inputs------\n" << endl;
		double* inp = get_input();
		for (int i = 0; i < get_input_size(); i++)
			cout << inp[i] << ", ";

		cout << endl;
		cout << endl;

		cout << "-------perceptron weights-----\n" << endl;
		double* w = get_weights();
		for (int i = 0; i < get_input_size(); i++)
			cout << w[i] << ", ";

		cout << endl;
		cout << endl;

		cout << "-------perceptron output------\n" << endl;
		cout << get_output() << endl;
		cout << endl;
	}
	cout << "==============================\n\n" << endl;
}


void Perceptron::WeightInitializer(
	string weight_initialize_function)
{
	if (weight_initialize_function == "constant")
	{
		for (int i = 0; i < input_size_; i++)
			weights_[i] = 0.1;

		weight_initialized_ = true;
	}
	else
	{
		cout << "weight initialize error" << endl;
	}

}

void Perceptron::Run()
{
	double weighted_sum = 0;
	for (int i = 0; i < input_size_; i++)
		weighted_sum = weights_[i] * input_[i] + weighted_sum;
	
	output_ = weighted_sum;
}