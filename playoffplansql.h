#ifndef PLAYOFFPLANSQL_H
#define PLAYOFFPLANSQL_H

#include "base.h"

#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QList>
#include <QDebug>
#include <QMessageBox>
#include <QtSql/QSqlError>

struct planStruct {
    QList<PlayOffRobot> AgentPlan[6];
    POMODE planMode;
    int agentSize;
    POInitPos initPos;
    QString tags;
    unsigned int chance;
    double lastDist;
};

struct planMData {
    POMODE planMode;
    int agentSize;
    QString tags;
    unsigned int chance;
    double lastDist;
};

class playOffPlanSQL
{
private:



public:
    playOffPlanSQL();
    ~playOffPlanSQL();

    bool changeSQLDir(QString directory);
    void savePlan();

    int loadPlan();
    int getPlanSize();

    void loadEachPlan(planStruct &_plan, QString _name);
    bool loadSQLtoStruct(QSqlQuery _query, int _rIndex, PlayOffRobot &temp);

    QList<planStruct> planList;

    int addPlan(QList<PlayOffRobot> tPlan[6],
                POInitPos tInitPos,
                POMODE tPOMode,
                QString tags,
                int agentSize,
                int itemId,
                unsigned int _chance = 1,
                double _lastDist = 1.5);

    int findMaxSteps(planStruct &_plan);
    void addEachPlanToSql(planStruct _plan, QString tName);
    void addStepToSql(QString tName, int tid,
                      QList<PlayOffRobot> &tA1,
                      QList<PlayOffRobot> &tA2,
                      QList<PlayOffRobot> &tA3,
                      QList<PlayOffRobot> &tA4,
                      QList<PlayOffRobot> &tA5,
                      QList<PlayOffRobot> &tA6);
    QString convertStructToSQLCmd(int _agentId, PlayOffRobot tStep);
    QString convertEmptyStructToSQLCmd();
    void insertPlanToQList(QList<PlayOffRobot> _planList[6], planMData &mData, int index);
    QSqlDatabase planSQL;

    void disableSQL();
    void enableSQL();
    void cleanPlans();
    void removePlan(int index);
};

#endif // PLAYOFFPLANSQL_H
