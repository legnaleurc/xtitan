#ifndef XTITAN_CLIENT_SPY_SPYMODEL_HPP
#define XTITAN_CLIENT_SPY_SPYMODEL_HPP

#include <QtCore/QObject>


namespace xtitan {

class SpyModel : public QObject {
	Q_OBJECT
public :
	explicit SpyModel();
	virtual ~SpyModel();

	void connectToHost( const QString & name );

	void stop();
	void check( const QString & label, const QString & value );
	void input( const QString & object, const QString & method, const QStringList & args, qint64 timeStamp );

signals:
	void ready();

private:
	class Private;
	Private * p_;
};

}

#endif
