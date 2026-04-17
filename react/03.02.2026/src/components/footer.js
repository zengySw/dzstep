function Footer() {
    const styles = {
        footer: {
            borderTop: "var(--global-green) solid 3px",
            color: "#fff",
            fontFamily: "Arial, sans-serif",
            marginTop: "60px",
        },

        top: {
            maxWidth: "1200px",
            margin: "0 auto",
            padding: "40px 20px",
            display: "grid",
            gridTemplateColumns: "repeat(4, 1fr)",
            gap: "32px",
        },

        colTitle: {
            fontSize: "14px",
            fontWeight: "700",
            marginBottom: "16px",
            textTransform: "uppercase",
            color: "var(--global-black-60)"
        },

        link: {
            fontSize: "14px",
            color: "var(--global-black)",
            marginBottom: "8px",
            cursor: "pointer",
        },

        bottom: {
            borderTop: "1px solid #3f3f3f",
            padding: "16px 20px",
            textAlign: "center",
            fontSize: "13px",
            color: "#aaa",
        },

        socials: {
            display: "flex",
            gap: "12px",
            marginTop: "12px",
        },

        socialIcon: {
            width: "32px",
            height: "32px",
            cursor: "pointer",
        },
    };

    return (
        <footer style={styles.footer}>
            <div style={styles.top}>
                <div>
                    <div style={styles.colTitle}>Покупцям</div>
                    <div style={styles.link} class="link">Доставка</div>
                    <div style={styles.link} class="link">Оплата</div>
                    <div style={styles.link} class="link">Гарантія</div>
                    <div style={styles.link} class="link">Повернення</div>
                </div>

                <div>
                    <div style={styles.colTitle}>Компанія</div>
                    <div style={styles.link} class="link">Про нас</div>
                    <div style={styles.link} class="link">Контакти</div>
                    <div style={styles.link} class="link">Вакансії</div>
                    <div style={styles.link} class="link">Новини</div>
                </div>

                <div>
                    <div style={styles.colTitle}>Допомога</div>
                    <div style={styles.link} class="link">FAQ</div>
                    <div style={styles.link} class="link">Підтримка</div>
                    <div style={styles.link} class="link">Безпека</div>
                </div>

                <div>
                    <div style={styles.colTitle}>Ми в соцмережах</div>
                    <div style={styles.socials}>
                        <img src="./images/facebook.svg" style={styles.socialIcon} />
                        <img src="./images/instagram.svg" style={styles.socialIcon} />
                        <img src="./images/youtube.svg" style={styles.socialIcon} />
                    </div>
                </div>
            </div>

            <div style={styles.bottom}>
                © 2026 ROZETKA — Інтернет-магазин
            </div>
        </footer>
    );
}

export default Footer;