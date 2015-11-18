#include <iostream>
#include <QtCore>

using std::cout;
using std::endl;

struct CommandLineArguments
{
	bool    verbose;
	QString outputFileName;
};

CommandLineArguments parseProgramArguments(
		QCoreApplication &app);

int main(int argc, char* argv[])
{
	QCoreApplication app(argc, argv);
	QCoreApplication::setApplicationName("Command-Parse");
	QCoreApplication::setApplicationVersion("0.0.0");
	
	const CommandLineArguments programArgs =
			parseProgramArguments(app);
	
	cout << "Verbose: " << programArgs.verbose << '\n'
			<< "Output File Name: "
			<< (programArgs.outputFileName.isNull() ?
					"(Not set)" :
					programArgs.outputFileName.toStdString())
			<< endl;
	
	return 0;
}

CommandLineArguments parseProgramArguments(
		QCoreApplication &app)
{
	QCommandLineOption verboseOption("verbose",
			"Output more information.");
	QCommandLineOption outputFileOption(
			QStringList() << "o" << "output", "Write data to <file>.",
			"file");
	
	QCommandLineParser parser;
	parser.setApplicationDescription(
			"Just testing out command-line parsing.");
	parser.addHelpOption();
	parser.addVersionOption();
	parser.addOption(outputFileOption);
	parser.addOption(verboseOption);
	
	parser.process(app);
	
	CommandLineArguments arguments;
	arguments.verbose = parser.isSet(verboseOption);
	arguments.outputFileName = parser.value(outputFileOption);
	return arguments;
}
