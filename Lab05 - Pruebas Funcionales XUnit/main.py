from selenium import webdriver
from selenium.webdriver.common.by import By
from webdriver_manager.chrome import ChromeDriverManager
from selenium.webdriver.chrome import service as ChromeService
import time



def test_eight_components():
    service = ChromeService(executable_path=ChromeDriverManager().install())

    driver = webdriver.Chrome(service=service)

    driver.get("https://www.selenium.dev/selenium/web/web-form.html")

    title = driver.title
    assert title == "Web form"

    driver.implicitly_wait(0.5)

    text_box = driver.find_element(by=By.NAME, value="my-text")
    submit_button = driver.find_element(by=By.CSS_SELECTOR, value="button")

    text_box.send_keys("Selenium")
    submit_button.click()
    driver.implicitly_wait(10)
    message = driver.find_element(by=By.ID, value="message")
    value = message.text

    print(value)

    assert value == "Received!"
    time.sleep(10)

    driver.quit()

if __name__ == "__main__":
    test_eight_components()