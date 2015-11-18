#include <iostream>
#include <QtCore>

using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
	QCoreApplication app(argc, argv);
	QCoreApplication::setApplicationName("Command-Parse");
	QCoreApplication::setApplicationVersion("0.0.0");
	
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
	
	bool verboseSet = parser.isSet(verboseOption);
	QString outputFileName = parser.value(outputFileOption);
	
	cout << "Verbose: " << verboseSet << '\n'
			<< "Output File Name: " << (outputFileName.isNull() ?
					"(Not set)" : outputFileName.toStdString()) << endl;
	
	return 0;
}
