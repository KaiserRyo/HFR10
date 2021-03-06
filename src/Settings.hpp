/*
 * Settings.hpp
 *
 *  Created on: 6 avr. 2014
 *      Author: pierre
 */

#ifndef SETTINGS_HPP_
#define SETTINGS_HPP_

#include <QtCore/QObject>
#include <QSettings>
#include <bb/cascades/ListView>
#include <bb/system/SystemUiResult>
#include <QSet>

class Settings : public QObject {

	Q_OBJECT

	Q_PROPERTY( int fontSize 	    READ getFontSize    WRITE setFontSize		NOTIFY fontSizeChanged)
	Q_PROPERTY( int smileySize 	    READ getSmileySize  WRITE setSmileySize		NOTIFY smileySizeChanged)
	Q_PROPERTY( int theme	 	    READ getTheme	    WRITE setTheme			NOTIFY themeChanged)
	Q_PROPERTY( int threadInterface READ getThreadInterface WRITE setThreadInterface NOTIFY threadInterfaceChanged)
	Q_PROPERTY( int autoRefresh	    READ getAutoRefresh WRITE setAutoRefresh    NOTIFY autoRefreshChanged)
	Q_PROPERTY( int askLeaveApp     READ getAskLeaveApp WRITE setAskLeaveApp    NOTIFY askLeaveAppChanged)
	Q_PROPERTY( bool hubIntegration  READ getHubIntegration WRITE setHubIntegration   NOTIFY hubIntegrationChanged)
	Q_PROPERTY( int hubRefreshRate  READ getHubRefreshRate WRITE setHubRefreshRate   NOTIFY hubRefreshRateChanged)

	Q_PROPERTY( bool notifGreen     READ getNotifGreen  WRITE setNotifGreen     NOTIFY notifGreenChanged)
	Q_PROPERTY( bool notifBlue      READ getNotifBlue   WRITE setNotifBlue      NOTIFY notifBlueChanged)
	Q_PROPERTY( bool notifOrange    READ getNotifOrange WRITE setNotifOrange    NOTIFY notifOrangeChanged)
	Q_PROPERTY( bool notifPink      READ getNotifPink   WRITE setNotifPink      NOTIFY notifPinkChanged)
	Q_PROPERTY( bool notifPurple    READ getNotifPurple WRITE setNotifPurple    NOTIFY notifPurpleChanged)

	Q_PROPERTY( bool enableLogs     READ getLogEnabled  WRITE setLogEnabled     NOTIFY logEnabledChanged)


private:


	static int m_FontSize;
	static int m_SmileySize;
	static int m_Theme;
	static int m_ThreadInterface;
	static int m_AutoRefresh;
	static bool m_HubIntegration;
	static int m_HubRefreshRate;
	static int m_AskLeaveApp;

	static bool m_NotifGreen;
	static bool m_NotifBlue;
	static bool m_NotifOrange;
	static bool m_NotifPink;
	static bool m_NotifPurple;

	static bool m_MPNotificationUp;
	static bool m_LogEnabled;

	static QMap<QString, int>   m_TopicTags;

	static QSettings        *m_Settings;
	bb::cascades::ListView  *m_BlackListView;
	QSet<QString>            m_BlackList;
	QString                  m_tmp_id;


public:
	Settings(QObject *parent = 0);
	virtual ~Settings() {}


	inline void setFontSize(int s) 						{ m_FontSize = s; }
	inline int  getFontSize() const						{ return m_FontSize; }

	inline void setTheme(int s) 						{ m_Theme = s; }
	inline int  getTheme() const						{ return m_Theme; }

	inline int  getThreadInterface() const              { return m_ThreadInterface; }
	inline void  setThreadInterface(int s)              { m_ThreadInterface = s; }

	inline void setSmileySize(int s) 					{ m_SmileySize = s; }
	inline int  getSmileySize() const				    { return m_SmileySize; }

	inline void setAutoRefresh(int s) 					{ m_AutoRefresh = s; }
	inline int  getAutoRefresh() const					{ return m_AutoRefresh; }

	inline void setAskLeaveApp(int s)                   { m_AskLeaveApp = s; }
    inline int  getAskLeaveApp() const                  { return m_AskLeaveApp; }

	static int  smileySize() 							{ return m_SmileySize; }
	static int  fontSize()								{ return m_FontSize; }

	static int  &themeValue()							{ return m_Theme; }

	inline void setHubIntegration(bool s)               { m_HubIntegration = s; }
	inline bool getHubIntegration() const               { return m_HubIntegration; }

	inline void setHubRefreshRate(int s)                { m_HubRefreshRate = s; }
	inline int getHubRefreshRate() const                { return m_HubRefreshRate; }

	inline void setNotifGreen(bool s)                   { m_NotifGreen = s; }
	inline bool getNotifGreen() const                   { return m_NotifGreen; }

	inline void setNotifBlue(bool s)                    { m_NotifBlue = s; }
	inline bool getNotifBlue() const                    { return m_NotifBlue; }

	inline void setNotifOrange(bool s)                  { m_NotifOrange = s; }
	inline bool getNotifOrange() const                  { return m_NotifOrange; }

	inline void setNotifPink(bool s)                    { m_NotifPink = s; }
	inline bool getNotifPink() const                    { return m_NotifPink; }

    inline void setNotifPurple(bool s)                  { m_NotifPurple = s; }
    inline bool getNotifPurple() const                  { return m_NotifPurple; }

    inline void setLogEnabled(bool s)                  { m_LogEnabled = s; }
    inline bool getLogEnabled() const                  { return m_LogEnabled; }

	static void	loadSettings();

	static int getTagValue(const QString& topicID);

	static bool getMPNotificationUp()                     { return m_MPNotificationUp; }
	static bool getLogEnabledUI()                         { return m_LogEnabled; }
	static void setMPNotificationUp(bool value)           { m_MPNotificationUp = value; }

public Q_SLOTS:
	void saveSettings() const;
	void saveColors() const;
	void updateHub() const;

	void setTag(const QString &topicID, int color);
	int  getTag(const QString &topicID) const;

	inline void setBlackListView        (QObject *list)                 { m_BlackListView = dynamic_cast<bb::cascades::ListView*>(list);};
	void loadBlackList                  ();
	void removeFromBlacklist            (const QString& id);
	void removeFromBlacklistNoAsk       (const QString& id);
	void onPromptFinishedRemoveFromBlacklist(bb::system::SystemUiResult::Type);

	// ----------------------------------------------------------------------------------------------
	Q_SIGNALS:
		void fontSizeChanged();
		void smileySizeChanged();
		void themeChanged();
		void threadInterfaceChanged();
		void autoRefreshChanged();
		void hubIntegrationChanged();
		void hubRefreshRateChanged();
		void notifGreenChanged();
		void notifBlueChanged();
		void notifOrangeChanged();
		void notifPinkChanged();
		void notifPurpleChanged();
		void logEnabledChanged();
		void askLeaveAppChanged();

};


#endif /* SETTINGS_HPP_ */
