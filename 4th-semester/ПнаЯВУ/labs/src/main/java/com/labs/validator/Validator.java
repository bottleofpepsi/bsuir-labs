package com.labs.validator;
import com.labs.entities.ValidationError;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.stereotype.Component;

@Component
public class Validator {
    private static final Logger logger = LoggerFactory.getLogger(Validator.class);
    
    public ValidationError validateParameter(String first, String second, String third) {
        ValidationError validatorResponse = new ValidationError();

        if (first == null || second == null || third == null) {

            logger.error("Ошибка валидации");
            validatorResponse.addErrormessage("Все параметры обязательны");
            return validatorResponse;
        }

        if (!first.matches("-?\\d+(\\.\\d+)?")) {

            logger.error("Ошибка валидации");
            if (first.isEmpty())
                validatorResponse.addErrormessage("Первый параметр пуст");
            else
                validatorResponse.addErrormessage("Первый параметр не является числом");
        }

        if (!second.matches("-?\\d+(\\.\\d+)?")) {

            logger.error("Ошибка валидации");
            if (second.isEmpty())
                validatorResponse.addErrormessage("Второй параметр пуст");
            else
                validatorResponse.addErrormessage("Второй параметр не является числом");
        }

        if (!third.matches("-?\\d+(\\.\\d+)?")) {

            logger.error("Ошибка валидации");
            if (third.isEmpty())
                validatorResponse.addErrormessage("Третий параметр пуст");
            else
                validatorResponse.addErrormessage("Третий параметр не является числом");
        }

        return validatorResponse;
    }

}