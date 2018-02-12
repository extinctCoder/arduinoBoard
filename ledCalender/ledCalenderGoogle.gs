function doGet(){
  var _calendarName = 'ledCalendar';
  var _checkInRate = 1000; // mills
  var retResult = {};
  var cal = CalendarApp.getCalendarsByName(_calendarName)[0];
  if(cal){
    var startTime = new Date();
    var endTime = new Date();
    endTime.setSeconds(startTime.getSeconds() + _checkInRate);
    var events = cal.getEvents(startTime, endTime);
    if(events.length){
      retResult = {status : true, ledStatus : true, msg : events.length+' events are scheduled.'};
    }
    else{
      retResult = {status : true, ledStatus : false, msg : 'no event is scheduled.'};
    }
  }
  else{
    retResult = {status : false, ledStatus : false, msg : _calendarName+' not found.'};
  }
  return ContentService.createTextOutput(JSON.stringify(retResult)).setMimeType(ContentService.MimeType.JSON);
}
