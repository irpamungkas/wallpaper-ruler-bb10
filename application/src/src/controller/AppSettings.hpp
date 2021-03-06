/*
 * AppSettings.h
 *
 *  Created on: Feb 3, 2013
 *      Author: williamrjribeiro
 */

#ifndef APPSETTINGS_HPP_
#define APPSETTINGS_HPP_

#include <QObject>

class AppSettings: public QObject {

	Q_OBJECT

    // The Date & Time the application was closed last time. Used for showing the Long Press Tutorial image on MFE.
    // It is saved as the app Setting APP_LAST_CLOSED.
    Q_PROPERTY(QString lastClosed READ lastClosed CONSTANT)

	// Indicates if the Long Press Tutorial image must be displayed
	Q_PROPERTY(bool showTutorial READ showTutorial WRITE setShowTutorial)

public:

	// The max days between the last time the app was used and now to show the tutorial: 7
	static const int APP_MAX_DAYS;

	// The String format used to save the date the app was last used: "dd/MM/yyyy hh:mm:ss"
	static const QString APP_DATE_FORMAT;

	// The Application language setting name.
	static const QString APP_LANG;

	// The Application lastClosed setting name
	static const QString APP_LAST_CLOSED;

	AppSettings(QObject *parent = 0);
	~AppSettings(){};

	QString lastClosed() const;

	bool	showTutorial() const;
	void	setShowTutorial(bool);

	/* Invokable functions that we can call from QML*/

	/**
	 * This Invokable function gets a value from the QSettings,
	 * if that value does not exist in the QSettings database, the default value is returned.
	 *
	 * @param settingName Index path to the item
	 * @param defaultValue Used to create the data in the database when adding
	 * @return If the objectName exists, the value of the QSettings object is returned.
	 *         If the objectName doesn't exist, the default value is returned.
	 */
	Q_INVOKABLE
	QString getValueFor(const QString &settingName, const QString &defaultValue);

	/**
	 * This function sets a value in the QSettings database. This function should to be called
	 * when a data value has been updated from QML
	 *
	 * @param settingName Index path to the item
	 * @param inputValue new value to the QSettings database
	 */
	Q_INVOKABLE
	void saveValueFor(const QString &settingName, const QString &inputValue);

private:
	QString m_lastClosed;
	bool	m_showTutorial;
};
#endif /* APPSETTINGS_HPP_ */
